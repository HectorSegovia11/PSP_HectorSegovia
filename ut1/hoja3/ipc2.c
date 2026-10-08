#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main(){
     int fd[2]; 
     char buffer[10];
     pid_t pid;
     int numeros[3]={3,5,2};
     int longitud_numeros= (sizeof(numeros)/sizeof(numeros[0]));
     int suma_acumulada=0;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); // Cierra el descriptor de escritura
                for (size_t i = 0; i < longitud_numeros; i++)
                {
                    int num;
                    read(fd[0], &num, sizeof(int));
                    printf("Numero a sumar:  %d \n", num);
                    suma_acumulada+=num;

                }
                char operacion;
                read(fd[0], &operacion, sizeof(char));
                printf("Recibido caracter:  %c \n", operacion);
                printf("Suma total es igual a :  %d \n", suma_acumulada);
                close(fd[0]);


                
     
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                for (size_t i = 0; i < longitud_numeros; i++)
                {
                    write(fd[1], &numeros[i],sizeof(int));
                }
                    char operacion = '+';
                    write(fd[1], &operacion ,sizeof(char));
                
                close(fd[1]);
                wait(NULL);    
     }
     
        
}
