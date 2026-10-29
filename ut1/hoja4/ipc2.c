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
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        close(pipe3[1]);
        close(pipe4[0]);
        close(pipe4[1]);

        float notas[10];
        read(pipe3[0], notas, sizeof(float) * 10);
        close(pipe3[0]);

        float suma = 0;
        float maxima = notas[0];

        for (int i = 0; i < 10; i++) {
            suma += notas[i];
            if (notas[i] > maxima) {
                maxima = notas[i];
            }
        }

        float resultados[2];
        resultados[0] = suma / 10.0;
        resultados[1] = maxima;

        write(pipe1[1], resultados, sizeof(float) * 2);
        close(pipe1[1]);

        exit(0);
    }

    p3 = fork();

    if (p3 == 0) {
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe3[0]);
        close(pipe3[1]);
        close(pipe4[1]);

        float notas[10];
        read(pipe4[0], notas, sizeof(float) * 10);
        close(pipe4[0]);

        int aprobados = 0;
        int suspensos = 0;

        for (int i = 0; i < 10; i++) {
            if (notas[i] >= 5.0) {
                aprobados++;
            } else {
                suspensos++;
            }
        }

        int resultados[2];
        resultados[0] = aprobados;
        resultados[1] = suspensos;

        write(pipe2[1], resultados, sizeof(int) * 2);
        close(pipe2[1]);

        exit(0);
    }

    close(pipe1[1]);
    close(pipe2[1]);
    close(pipe3[0]);
    close(pipe4[0]);

    float notas[10];
    for (int i = 0; i < 10; i++) {
        do {
            printf("Introduce la nota del alumno %d (0 a 10): ", i + 1);
            scanf("%f", &notas[i]);
        } while (notas[i] < 0 || notas[i] > 10);
    }

    write(pipe3[1], notas, sizeof(float) * 10);
    close(pipe3[1]);

    write(pipe4[1], notas, sizeof(float) * 10);
    close(pipe4[1]);

    float resultados_p2[2];
    read(pipe1[0], resultados_p2, sizeof(float) * 2);
    close(pipe1[0]);

    int resultados_p3[2];
    read(pipe2[0], resultados_p3, sizeof(int) * 2);
    close(pipe2[0]);

    wait(NULL);
    wait(NULL);

    printf("\n resultados\n");
    printf("media: %.2f\n", resultados_p2[0]);
    printf("Nota máxima: %.2f\n", resultados_p2[1]);
    printf("Alumnos aprobados: %d\n", resultados_p3[0]);
    printf("Alumnos suspensos: %d\n", resultados_p3[1]);

    return 0;
}
