#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main(){
     time_t hora;
     char *fecha ;
     int fd[2]; 
     char buffer[100];
     pid_t pid;

     time(&hora);
     fecha = ctime(&hora);
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); // Cierra el descriptor de escritura
                printf("Soy el proceso hijo con pid: %d \n", getpid());
                read(fd[0], buffer, 100);
                printf("\t Fecha y hora:  %s \n", buffer);
     
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                char mensaje[100];
                snprintf(mensaje,sizeof(mensaje), "%s", fecha);
                write(fd[1], mensaje, 100);  
                wait(NULL);    
     }
     
        
}
