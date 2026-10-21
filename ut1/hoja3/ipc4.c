#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    pid_t pid;

    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if (pid == 0) {
        close(pipe1[1]);
        close(pipe2[0]);

        int numero;
        read(pipe1[0], &numero, sizeof(int));
        close(pipe1[0]);

        long factorial = 1;
        for (int i = 1; i <= numero; i++) {
            factorial *= i;
        }

        write(pipe2[1], &factorial, sizeof(long));
        close(pipe2[1]);

        exit(0);
    } 
    else {
        close(pipe1[0]);
        close(pipe2[1]);

        srand(getpid());
        int numero = rand() % 11;

        printf("El proceso padre genera el numero %d en el pipe1\n", numero);

        write(pipe1[1], &numero, sizeof(int));
        close(pipe1[1]);

        long resultado;
        read(pipe2[0], &resultado, sizeof(long));
        close(pipe2[0]);

        wait(NULL);

        printf("El factorial calculado por el proceso hijo: %d != %ld\n", numero, resultado);
    }

    return 0;
}
