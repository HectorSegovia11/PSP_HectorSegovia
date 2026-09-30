#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
 pid2 = fork();
 printf("CCC \n");
 }
 exit(0);
}

// a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo
// que el pid del programa fork8 es el 1000 y los pids se generan de uno en uno en orden creciente.
// P3-----P1----P2
// b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
// La salida sera de AAA y luego puede ser BBB CCC CCC o CCC CCC BBB ya que el CCC lo ejecutan tanto el P1 como el P3
// c) Añade el código necesario para que el orden de ejecución sea tal que los respectivos procesos
// padre sean los últimos que se ejecuten.
// Seria añadir un wait en el else yya antes de hacer el fork asi nos aseguramos que sea AAA BBB CCC CCC
