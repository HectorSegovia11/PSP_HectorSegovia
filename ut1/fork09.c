#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_2,pid_3;

    printf("Soy P1 y empiezo \n");


    pid = fork();

    if (pid == 0) {
        printf("Soy P2 y empiezo \n");
        sleep(5);
        printf("Soy P2 y termino \n");
        exit(0);
    } 
    else {
        pid_2 = fork();

        if (pid_2 == 0)
        {
            printf("Soy P3 y empiezo \n");
            sleep(2);
            printf("Soy P3 y termino \n");
            exit(0);
        } else {
            pid_3 = fork();

            if (pid_3==0)
            {
                printf("Soy P4 y empiezo \n");
                sleep(4);
                printf("Soy P4 y termino\n");
                exit(0);
            }
            
        }
        
        printf("Soy P1 y termino \n");

    }

    return 0;
}

// a) ¿Podemos asegurar ahora qué proceso terminará primero?
// Si el primero sera P1 luego P3 Luego P4 y luego P2
// b) Si eliminamos la instrucción sleep() ¿cuál sería el orden de terminación?
// Seria aleatorio depende de como le vayan entrando las ordenes al procesador
