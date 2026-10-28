#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    pid_t pid;

    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if (pid == 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        int dni;
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dni);

        write(pipe1[1], &dni, sizeof(int));
        close(pipe1[1]);

        char letra;
        read(pipe2[0], &letra, sizeof(char));
        close(pipe2[0]);

        printf("la letra del NIF es %c\n", letra);

        exit(0);
    } 
    else {
        close(pipe1[1]);
        close(pipe2[0]);

        int dni;
        read(pipe1[0], &dni, sizeof(int));
        close(pipe1[0]);

        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        char resultado = letra[dni % 23];

        write(pipe2[1], &resultado, sizeof(char));
        close(pipe2[1]);

        wait(NULL);
    }

    return 0;
}
