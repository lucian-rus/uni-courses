#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

// programul NU poate scrie peste datele curente, face append
// pentru a scrie peste datele curente, trebuie sa scoatem flag-ul de append

int main(void)
{
    int fd = open("testfile.txt", O_RDWR | O_APPEND);
    if(-1 == fd) {
        printf("err when opening\n");
        return -1;
    }

    char char_read = 0;
    char to_write = 'v';


    // no error handling here
    lseek(fd, 14, SEEK_SET);
    read(fd, &char_read, 1);
    printf("%c\n", char_read);
    write(fd, &to_write, 1);

    lseek(fd, 36, SEEK_SET);
    read(fd, &char_read, 1);
    printf("%c\n", char_read);
    write(fd, &to_write, 1);

    if(-1 == close(fd)) {
        printf("err when closing\n");
        return -1;
    }

    return 0;
}
