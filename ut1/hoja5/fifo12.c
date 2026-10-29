#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    mkfifo("FIFO2", 0666);

    int fd1 = open("FIFO1", O_RDONLY);
    int numero;
    read(fd1, &numero, sizeof(int));
    close(fd1);

    long factorial = 1;
    for (int i = 1; i <= numero; i++) {
        factorial *= i;
    }

    int fd2 = open("FIFO2", O_WRONLY);
    write(fd2, &factorial, sizeof(long));
    close(fd2);

    unlink("FIFO2");

    return 0;
}
