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
// Se ejecutara siempre en el siguiente orden P2 P4 P3 P1 ya que primero se hace fork de p1 y hasta que no acaba p2 p1 no puede seguir p1 crea p3 y p3 a p4 y como p4 no tiene hijos es el siguiente en terminar luego p3 al quedarse sin hijo y por ultimo p1