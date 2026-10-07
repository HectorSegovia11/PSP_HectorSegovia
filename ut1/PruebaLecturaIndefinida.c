#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int limite = 100;
    int numero[limite];

    for (size_t i = 0; i < limite; i++)
    {
        numero[i]= i+1;
    }
    
    int longitud_numero = (sizeof(numero)/sizeof(numero[0]));

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);

        for (size_t i = 0; i < longitud_numero; i++)
        {
            int recibido;
            read(fd[0], &recibido, sizeof(recibido));
            printf("HIJO: He recibido %d\n", recibido);
        }
        

        close(fd[0]);
    }
    else {
        // PADRE: solo escribe
        close(fd[0]);

        for (size_t i = 0; i < longitud_numero; i++){
            write(fd[1], &numero[i], sizeof(numero[i]));

            printf("PADRE: He enviado %d\n", numero[i]);

        }
        

        close(fd[1]);

        wait(NULL);
    }


}
