#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2;

    pid = fork();

    if (pid == 0) {
        
        int resultado = 0;
        for (size_t i = 1; i <= 100; i++)
        {
            resultado += i;
        }
        printf("P2 Mi PID es %d y el PID de mi padre es %d y el resultado de la sucecion de 1..100 es de %d\n", getpid(), getppid(),resultado);
        exit(0);
    } 
    else {
        pid_2 = fork();

        if (pid_2 == 0)
        {
            int resultado = 0;
            for (size_t i = 101; i <= 200; i++)
            {
                resultado += i;
            }
            printf("P2 Mi PID es %d y el PID de mi padre es %d y el resultado de la sucecion de 101..200 es de %d\n", getpid(), getppid(),resultado);
            exit(0);
        }
        
        wait(NULL);
        wait(NULL);
        printf("Todos los calculos han terminado \n");

    }

    return 0;
}