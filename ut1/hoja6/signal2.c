#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int segundos = 0;

void alarma(int sig) {
    segundos += 5;
    printf("Han transcurrido %d segundos\n", segundos);
    alarm(5);
}

int main() {
    signal(SIGALRM, alarma);
    alarm(5);

    pause();
    return 0;
}
