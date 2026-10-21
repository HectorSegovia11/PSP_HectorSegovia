#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    pipe(fd);

    pid = fork();

    if (pid == 0) {
        close(fd[1]);

        char entrada[20];
        int sumatotal = 0;

        do {
            read(fd[0], entrada, sizeof(entrada));

            if (entrada[0] != '+') {
                int num = atoi(entrada);
                printf("Numero a sumar: %d\n", num);
                sumatotal += num;
            } else {
                printf("Recibido carácter +\n");
            }

        } while (entrada[0] != '+');

        printf("La suma total es igual a: %d\n", sumatotal);

        close(fd[0]);
        exit(0);
    } 
    else {
        close(fd[0]);

        char entrada[20];

        do {
            scanf("%s", entrada);
            write(fd[1], entrada, sizeof(entrada));
        } while (entrada[0] != '+');

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
