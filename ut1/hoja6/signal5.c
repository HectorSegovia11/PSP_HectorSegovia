#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int fd[2];

void leer(int sig) {
    int num;
    read(fd[0], &num, sizeof(int));
    if (num % 2 == 0)
        printf("Número par %d recibido por el proceso P2 con pid %d\n", num, getpid());
    else
        printf("Número impar %d recibido por el proceso P3 con pid %d\n", num, getpid());
}

int main() {
    pipe(fd);

    pid_t p2 = fork();
    if (p2 == 0) {
        signal(SIGUSR1, leer);
        while (1) pause();
    }

    pid_t p3 = fork();
    if (p3 == 0) {
        signal(SIGUSR1, leer);
        while (1) pause();
    }

    int num;
    while (1) {
        printf("Introduce número:");
        scanf("%d", &num);

        if (num == 0) {
            printf("Mandando señal de terminación al proceso hijo P2 con pid %d\n", p2);
            kill(p2, SIGKILL);
            printf("Mandando señal de terminación al proceso hijo P3 con pid %d\n", p3);
            kill(p3, SIGKILL);
            printf("Fin proceso padre con pid %d\n", getpid());
            break;
        }

        write(fd[1], &num, sizeof(int));
        if (num % 2 == 0)
            kill(p2, SIGUSR1);
        else
            kill(p3, SIGUSR1);
        
        sleep(1);
    }

    return 0;
}
