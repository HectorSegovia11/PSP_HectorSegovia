#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2,pid_3;



    pid = fork();

    if (pid == 0) {
        if (getpid() % 2 == 0)
        {
            printf("Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

        } else {
             printf("Mi PID es %d \n", getpid());
        }

    } 
    else 
    {

        pid_2 = fork();

        if (pid_2 == 0)
        {
            pid_3 = fork();

            if (pid_3 == 0)
            {
                
                if (getpid() % 2 == 0)
                {
                    printf("Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

                } else {
                    printf("Mi PID es %d \n", getpid());
                }
                
            
            } else {
                
                
                wait(NULL);
                if (getpid() % 2 == 0)
                {
                    printf("Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

                } else {
                    printf("Mi PID es %d \n", getpid());
                }
                
            }
        
        } else {
            wait(NULL);
            wait(NULL);
            if (getpid() % 2 == 0)
            {
                printf("Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

            } else {
                 printf("Mi PID es %d \n", getpid());
            }
            
        }
        

    }

    return 0;
}
//a) ¿Cuál será el orden de ejecución de los procesos?¿Será siempre el mismo? Justifica la respuesta
// Podra haber 3 ordenes de ejecucion diferentes que mueran en este orden P2-P4-P3-P1 en este P4-P3-P2-P1 o en este P4-P2-P3-P1 ya que tanto p2 como p4 no tienen hijos a si que cualquiera de ellos puede ser el primero en morir y si muere primero el p4 p3 se queda sin hijo por lo que tambien se une a la pelea con p2 por ver quien muere
