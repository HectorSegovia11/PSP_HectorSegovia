#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo;
  
  
  // Se crea un proceso hijo, la función fork() devuelve:
  // un valor negativo -> si se produce cualquier error
  // 0 -> si estamos en el proceso hijo
  // un valor positivo (pid del hijo) -> si estamos en el proceso padre

  pid = fork();

  if (pid == -1 ) 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (pid == 0 )  
  {        
    printf("Soy el proceso HIJO \n");
    printf("Mi PID es %d \n", getpid());
    printf("El PID de mi padre es %d \n", getppid());

    
  }
  else   
  { 
    pid_hijo = wait(NULL); 
    printf("Soy el proceso PADRE \n");
    printf("Mi PID es %d \n", getpid());
    printf("Mi hijo tenia el PID %d \n", pid_hijo);
    printf("El proceso hijo ya ha termiando");      
  }
   exit(0);
}