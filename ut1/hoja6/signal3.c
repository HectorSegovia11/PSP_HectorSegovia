#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int intentos = 0;

void captura(int sig) {
    intentos++;
    time_t t = time(NULL);
    FILE *f = fopen("salidas.txt", "a");
    if (f) {
        fprintf(f, "Intento %d: %s", intentos, ctime(&t));
        fclose(f);
    }
}

int main() {
    signal(SIGINT, captura);

    while (1) pause();
    return 0;
}
