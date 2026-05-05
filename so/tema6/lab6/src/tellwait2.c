#include "ourhdr.h"
#include "sys/wait.h"
#include <sys/types.h>

static void charatatime(char *);

int main(void) {
    pid_t pid;

    TELL_WAIT();

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) {
        // WAIT_PARENT();		/* parent goes first */
        charatatime("output from child\n");
    }
    else {
        wait(NULL); // folosim `wait` pentru ca e mai usor de folosit
        charatatime("output from parent\n");
        TELL_CHILD(pid);
    }
    exit(0);
}

static void charatatime(char *str) {
    char *ptr;
    int   c;

    setbuf(stdout, NULL); /* set unbuffered */
    for (ptr = str; c = *ptr++;) putc(c, stdout);
}
