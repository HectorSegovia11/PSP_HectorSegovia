#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    mkfifo("FIFO1", 0666);

    srand(getpid());
    int numero = rand() % 11;

    printf("El proceso fifo11 genera el numero %d en el FIFO1\n", numero);

    int fd1 = open("FIFO1", O_WRONLY);
    write(fd1, &numero, sizeof(int));
    close(fd1);

    int fd2 = open("FIFO2", O_RDONLY);
    long resultado;
    read(fd2, &resultado, sizeof(long));
    close(fd2);

    printf("El factorial calculado por el proceso fifo12: %d != %ld\n", numero, resultado);

    unlink("FIFO1");

    return 0;
}
