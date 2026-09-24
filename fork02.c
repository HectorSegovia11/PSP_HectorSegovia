#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_terminado;

    pid = fork();

    if (pid < 0) {
        perror("Error al ejecutar fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        
        printf("HIJO Hola, soy el alumno: Juan Pérez\n");
        printf("HIJO Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
        exit(0);
    } 
    else {
        
        pid_terminado = wait(NULL);

        printf("PADRE Soy el proceso padre (PID: %d)\n", getpid());
        printf("PADRE Mi hijo (PID: %d) ha terminado su ejecución.\n", pid_terminado);
    }

    return 0;
}