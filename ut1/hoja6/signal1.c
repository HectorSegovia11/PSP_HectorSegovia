#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void fin(int sig) {
    time_t t = time(NULL);
    printf("\n Fin del proceso %d: %s",getpid(), ctime(&t));
    exit(0);
}

int main() {
    signal(SIGINT, fin);

    time_t t = time(NULL);
    printf("Inicio del proceso %d: %s", getpid(), ctime(&t));

    while (1) pause();
    return 0;
}
