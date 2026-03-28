#include "ourhdr.h"
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */
    if (stat(argv[1], &statbuf) < 0) {
        err_sys("stat error for %s", argv[1]);
    }
    if (chmod(argv[1], (statbuf.st_mode | S_ISUID)) < 0) {
        err_sys("chmod error for %s", argv[1]);
    }

    exit(0);
}
