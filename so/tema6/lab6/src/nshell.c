#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    printf("starting custom shell...\n");

    bool main_proc_exit = false;
    while (true) {
        printf("\033[1;32mcustomshell-user\033[0m$ ");
        char aux[256] = {0};
        scanf("%s", aux);

        // daca e main proc, iesim doar la comanda exit
        if (strcmp(aux, "exit") == 0) {
            main_proc_exit = true;
            break;
        }

        // fork ca sa putem executa
        int pid = fork();
        if (pid == 0) {
            // daca e child proc, facem totul aici
            int res = execlp(aux, aux, NULL);
            if (res != 0) {
                printf("error when running command \033[1;32m%s\033[0m\n", aux);
            }

            // iesim ca sa oprem child proc
            break;
        }
        else {
            wait(NULL);
        }
    }

    // printam doar daca am iesit din main proc
    if (main_proc_exit == true) {
        printf("stopping custom shell...\n");
    }
    return 0;
}