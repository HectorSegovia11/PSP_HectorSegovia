#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_terminado;

    pid = fork();

    if (pid == 0) {
        printf("P2 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
        sleep(3);
        exit(0);
    } 
    else {
        pid = fork();

        if (pid == 0)
        {
            printf("P3 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
            sleep(2);
            exit(0);
        }
        
        
        pid_terminado = wait(NULL);
        pid_terminado = wait(NULL);
        printf("P1 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
        printf("Todos mis hijos han terminado \n");

    }

    return 0;
}