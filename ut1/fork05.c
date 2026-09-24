#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2;

    pid = fork();

    if (pid == 0) {
        pid_2 = fork();
        if (pid_2 == 0)
        {
            printf("P3 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
            exit(0);
        }
        wait(NULL);
        printf("P2 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
        exit(0);
    } 
    else {
        wait(NULL);
        printf("P1 Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

    }

    return 0;
}