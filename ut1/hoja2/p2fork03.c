#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2, pid_3,pid_4,pid_5, abuelo1, abuelo2;
    abuelo2 = getpid();
    pid = fork();
    if (pid == 0) 
    {
        abuelo1 = getpid();
        pid_2 = fork();
        if (pid_2 == 0) 
        {
            
            pid_3 = fork();
            
            if (pid_3 == 0)
            {
                printf("Soy P5 Mi PID es %d y el PID de mi abuelo es %d\n", getpid(),abuelo1);

            } else {
                wait(NULL);
                printf("Soy P3 Mi PID es %d y el PID de mi abuelo es %d\n", getpid(),abuelo2);

            }     
        }
        else 
        {
            pid_4 = fork();
            
            if (pid_4 == 0)
            {
                pid_5 = fork();
                if (pid_5 == 0)
                {
                    printf("Soy P6 Mi PID es %d y el PID de mi abuelo es %d\n", getpid(),abuelo1);
                } 
                else 
                {
                    wait(NULL);
                    printf("Soy P4 Mi PID es %d y el PID de mi abuelo es %d\n", getpid(),abuelo2);
                }

            } else {
                wait(NULL);
                wait(NULL);
                printf("Soy P2 Mi PID es %d y el PID de mi padre es %d\n", getpid(),getppid());

            } 
            
        }
        
    } 
    else 
    {
        wait(NULL);
        printf("Soy P1 Mi PID es %d\n", getpid());
    }

    return 0;
}