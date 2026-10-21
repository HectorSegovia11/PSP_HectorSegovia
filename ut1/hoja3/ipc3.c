#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Error al hacer fork");
        return 1;
    }

    if (pid == 0) {
        close(fd[0]);

        srand(getpid());

        int num1 = (rand() % 50) + 1;
        int num2 = (rand() % 50) + 1;

        printf("[HIJO] Números generados: %d y %d. Enviando por el pipe...\n", num1, num2);

        write(fd[1], &num1, sizeof(int));
        write(fd[1], &num2, sizeof(int));

        close(fd[1]);
        exit(0);
    } 
    else {
        close(fd[1]);

        int n1, n2;

        read(fd[0], &n1, sizeof(int));
        read(fd[0], &n2, sizeof(int));

        close(fd[0]);

        wait(NULL);

        printf("\n[PADRE] Datos recibidos del hijo:\n");
        printf("  - Suma (%d + %d) = %d\n", n1, n2, n1 + n2);
        printf("  - Resta (%d - %d) = %d\n", n1, n2, n1 - n2);
        printf("  - Producto (%d * %d) = %d\n", n1, n2, n1 * n2);
        
        if (n2 != 0) {
            printf("  - División (%d / %d) = %.2f\n", n1, n2, (float)n1 / n2);
        } else {
            printf("  - División: Indeterminada (división por cero)\n");
        }
    }

    return 0;
}
