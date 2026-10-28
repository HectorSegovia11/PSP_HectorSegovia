#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    int pipe3[2];
    int pipe4[2];

    pid_t p2, p3;

    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);
    pipe(pipe4);

    p2 = fork();

    if (p2 == 0) {
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        close(pipe3[0]);
        close(pipe4[0]);
        close(pipe4[1]);

        int nums[2];
        read(pipe1[0], nums, sizeof(int) * 2);
        close(pipe1[0]);

        int suma = nums[0] + nums[1];

        write(pipe3[1], &suma, sizeof(int));
        close(pipe3[1]);

        exit(0);
    }

    p3 = fork();

    if (p3 == 0) {
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe3[0]);
        close(pipe3[1]);
        close(pipe4[0]);

        int nums[2];
        read(pipe2[0], nums, sizeof(int) * 2);
        close(pipe2[0]);

        int producto = nums[0] * nums[1];

        write(pipe4[1], &producto, sizeof(int));
        close(pipe4[1]);

        exit(0);
    }

    close(pipe1[0]);
    close(pipe2[0]);
    close(pipe3[1]);
    close(pipe4[1]);

    int numeros[2];
    printf("Introduce el primer número: ");
    scanf("%d", &numeros[0]);
    printf("Introduce el segundo número: ");
    scanf("%d", &numeros[1]);

    write(pipe1[1], numeros, sizeof(int) * 2);
    close(pipe1[1]);

    write(pipe2[1], numeros, sizeof(int) * 2);
    close(pipe2[1]);

    int suma, producto;
    read(pipe3[0], &suma, sizeof(int));
    close(pipe3[0]);

    read(pipe4[0], &producto, sizeof(int));
    close(pipe4[0]);

    wait(NULL);
    wait(NULL);

    printf("La suma calculada por P2 es: %d\n", suma);
    printf("El producto calculado por P3 es: %d\n", producto);

    return 0;
}
