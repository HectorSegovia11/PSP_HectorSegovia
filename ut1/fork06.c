#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2;

    pid = fork();

    if (pid == 0) {
        sleep(10);
        printf("Despierto \n");
        exit(0);
    } 
    else {
        pid_2 = fork();

        if (pid_2 == 0)
        {
            printf("P3 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
            exit(0);
        }
        
        
        wait(NULL);
        wait(NULL);
        printf("P1 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
        printf("Todos mis hijos han terminado \n");

    }

    return 0;
}