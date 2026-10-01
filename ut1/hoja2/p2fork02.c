#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2, pid_3;

    pid = fork();

    if (pid == 0) 
    {
        pid_2 = fork();

        if (pid_2 == 0) 
        {
            pid_3 = fork();
            if (pid_3 == 0) 
            {
                printf("Soy P4 Mi PID es %d y el PID de mi padre es %d y la suma de ambos es de %d\n", getpid(), getppid(), getpid() + getppid());
            } 
            else 
            {
                wait(NULL);
                printf("Soy P3 Mi PID es %d y el PID de mi padre es %d y la suma de ambos es de %d\n", getpid(), getppid(), getpid() + getppid());

            }
                
        } 
        else 
        {
            wait(NULL);
            printf("Soy P2 Mi PID es %d y el PID de mi padre es %d y la suma de ambos es de %d\n", getpid(), getppid(), getpid() + getppid());
        }
    } 
    else 
    {
        wait(NULL);
        printf("Soy P1 Mi PID es %d y el PID de mi padre es %d y la suma de ambos es de %d\n", getpid(), getppid(), getpid() + getppid());
    }

    return 0;
}