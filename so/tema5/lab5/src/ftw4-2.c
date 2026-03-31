#include "ourhdr.h"
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

/* function type that's called for each filename */
typedef int Myfunc(const char *, const struct stat *, int);

static Myfunc myfunc;
static int    myftw(char *, Myfunc *);
static int    dopath(Myfunc *);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[]) {
    int ret;

    if (argc != 2)
        err_quit("usage:  ftw  <starting-pathname>");

    ret = myftw(argv[1], myfunc); /* does it all */

    if ((ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock) == 0)
        ntot = 1; /* avoid divide by 0; print 0 for all counts */

    printf("regular files  = %7ld, %5.2f %%\n", nreg, nreg * 100.0 / ntot);
    printf("directories    = %7ld, %5.2f %%\n", ndir, ndir * 100.0 / ntot);
    printf("block special  = %7ld, %5.2f %%\n", nblk, nblk * 100.0 / ntot);
    printf("char special   = %7ld, %5.2f %%\n", nchr, nchr * 100.0 / ntot);
    printf("FIFOs          = %7ld, %5.2f %%\n", nfifo, nfifo * 100.0 / ntot);
    printf("symbolic links = %7ld, %5.2f %%\n", nslink, nslink * 100.0 / ntot);
    printf("sockets        = %7ld, %5.2f %%\n", nsock, nsock * 100.0 / ntot);

    exit(ret);
}

/*
 * Descend through the hierarchy, starting at "pathname".
 * The caller's func() is called for every file.
 */

#define FTW_F    1 /* file other than directory */
#define FTW_D    2 /* directory */
#define FTW_DNR  3 /* directory that can't be read */
#define FTW_NS   4 /* file that we can't stat */
#define FTW_NPWD 5 /* eroare aditionala pentru pwd error */

static char *fullpath; /* contains full pathname for every file */

static int myftw(char *pathname, Myfunc *func) {

    // fullpath = path_alloc(NULL);	/* malloc's for PATH_MAX+1 bytes */
    // strcpy(fullpath, pathname);	/* initialize fullpath */

    // pornim de la sursa
    if (chdir(pathname) < 0) {
        err_ret("error chdir %s", pathname);
        return -1;
    }
    return dopath(func);
}
static int dopath(Myfunc *func) {
    struct stat    statbuf;
    struct dirent *dirp;
    DIR           *dp;
    int            ret = 0;
    char          *ptr;

    // luam directorul curent
    char curr[256] = {0};
    if (getcwd(curr, 256) == NULL) {
        printf("eroare la deschidere\n");
        return func(curr, &statbuf, FTW_NS);
    }

    // printf("current: %s\n", curr);

    if (lstat(curr, &statbuf) < 0)
        return func(curr, &statbuf, FTW_NS); /* stat error */

    if (S_ISDIR(statbuf.st_mode) == 0)
        return func(curr, &statbuf, FTW_F); /* not a directory */

    /*
     * It's a directory.  First call func() for the directory,
     * then process each filename in the directory.
     */

    if ((ret = func(curr, &statbuf, FTW_D)) != 0)
        return ret;

    // ptr = fullpath + strlen(fullpath);	/* point to end of fullpath */
    // *ptr++ = '/';
    // *ptr = 0;

    if ((dp = opendir(curr)) == NULL)
        return func(curr, &statbuf, FTW_DNR);

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue; /* ignore dot and dot-dot */

        // strcpy(ptr, dirp->d_name);	/* append name after slash */

        struct stat entry;
        if (lstat(dirp->d_name, &entry) < 0)
            continue;

        // cum folosim chdir, trebuie sa ne asiguram ca ne intoarcem corect
        if (S_ISDIR(entry.st_mode)) {
            if (chdir(dirp->d_name) == 0) {
                if ((ret = dopath(func)) != 0) { /* recursive */
                    chdir("..");
                    break; /* time to leave */
                }
                chdir("..");
            }
        }
        else {
            if ((ret = func(dirp->d_name, &entry, FTW_F)) != 0)
                break;
        }
    }

    // ptr[-1] = 0;	/* erase everything from slash onwards */

    if (closedir(dp) < 0)
        err_ret("can't close directory %s", curr);

    return ret;
}

static int myfunc(const char *pathname, const struct stat *statptr, int type) {
    switch (type) {
        case FTW_F:
            switch (statptr->st_mode & S_IFMT) {
                case S_IFREG:
                    nreg++;
                    break;
                case S_IFBLK:
                    nblk++;
                    break;
                case S_IFCHR:
                    nchr++;
                    break;
                case S_IFIFO:
                    nfifo++;
                    break;
                case S_IFLNK:
                    nslink++;
                    break;
                case S_IFSOCK:
                    nsock++;
                    break;
                case S_IFDIR:
                    err_dump("for S_IFDIR for %s", pathname);
                    /* directories should have type = FTW_D */
            }
            break;

        case FTW_D:
            ndir++;
            break;

        case FTW_DNR:
            err_ret("can't read directory %s", pathname);
            break;

        case FTW_NS:
            err_ret("stat error for %s", pathname);
            break;

        case FTW_NPWD:
            err_ret("could not get pwd %s", pathname);
            break;

        default:
            err_dump("unknown type %d for pathname %s", type, pathname);
    }

    return 0;
}
