#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int veces, segundos, contador = 0;

void alarma(int sig) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char hora[10];
    strftime(hora, sizeof(hora), "%H:%M:%S", tm_info);

    printf("Señal de alarma recibida a las %s\n", hora);
    contador++;

    if (contador < veces) {
        alarm(segundos);
    }
}

int main() {
    printf("¿Cuántas veces sonará la alarma?:\n");
    scanf("%d", &veces);
    printf("¿Cada cuántos segundos se repetirá la alarma?:\n");
    scanf("%d", &segundos);

    signal(SIGALRM, alarma);
    printf("Alarma activada\n");
    alarm(segundos);

    while (contador < veces) {
        pause();
    }

    printf("Alarma desactivada\n");
    return 0;
}
