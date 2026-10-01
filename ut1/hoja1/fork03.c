printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
if (pid == 0) {
 printf("Soy el hijo\n");
} else {
 printf("Soy el padre\n");
}
printf("Fin\n");

// ¿Cuántos procesos existen?
// existen 2 procesos
// ¿ qué instrucciones ejecuta cada uno?
// ambos ejecutan el print de despues del fork y luego el hijo ejecuta la linea 5 y el padre la 7
// ¿cuántas veces aparece cada mensaje y qué partes de la salida pueden aparecer en distinto
// orden?
// el print de despues del fork aparece 2 veces y despues lo de padre e hijo pued esalir en cualquier orden
