#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int fd[2];
    int numero1 = 25;
    int numero2 = 50;
    ssize_t bytesleidos;

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);
        int recibido1;
        while (bytesleidos=read(fd[0],&recibido1, sizeof(recibido1)))
        {
            printf("HIJO: He recibido %d\n", recibido1);

        }

        close(fd[0]);
        printf("HIJO ha terminado \n");
    }
    else {
        // PADRE: solo escribe
        int cont=1;
        close(fd[0]);
        do
        {
         write(fd[1], &cont, sizeof(cont));
         printf("PADRE: He enviado %d\n", cont);
         cont++;
        } while (cont<=10);

        close(fd[1]); //Ya no se envían más números
        wait(NULL);
        printf("PADRE ha terminado \n");

    }



}
