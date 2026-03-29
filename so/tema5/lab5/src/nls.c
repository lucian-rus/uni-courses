#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    char curr[256];
    // ideal era sa folosim `get_current_dir_name`, dar folosim `getcwd` ca sa ramanem posix-compliant
    if (getcwd(curr, 256) == NULL) {
        printf("eroare la deschidere\n");
        return -1;
    }
    DIR *dir = opendir(curr);

    struct dirent *entry;
    // entry e un pointer la dir-ul curent, daca reapelam functia, inaintam pointer-ul la toate celelalte entitati care se afla in
    // directorul target
    while ((entry = readdir(dir)) != NULL) {
        struct stat buf;
        if (lstat(entry->d_name, &buf) < 0) {
            printf("lstat error for %s", entry->d_name);
            continue;
        }

        // facem stat ca sa verificam bit-ul de executie. daca e setat pentru oricare dintre situatiile de mai jos printam textul
        // cu un format verde bold, asemanator unui terminal clasic, dupa care resetam culoarea textului
        if (buf.st_mode & (S_IXGRP | S_IXOTH | S_IXUSR)) {
            printf("\033[1;32m%s\033[0m\n", entry->d_name);
        }
        else {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);

    return 0;
}