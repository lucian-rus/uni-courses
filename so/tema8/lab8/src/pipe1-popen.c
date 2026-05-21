#include "ourhdr.h"

int main(void) {
    FILE *fp;
    char  line[MAXLINE];

    if ((fp = popen("cat", "w")) == NULL)
        err_sys("popen error");

    // punem hello world in stream-ul dat de pipe
    fputs("hello world\n", fp);

    if (pclose(fp) < 0)
        err_sys("pclose error");

    exit(0);
}
