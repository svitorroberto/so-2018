/* prog3.c – múltiplas threads */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#define NTHREADS 10
void *CPU_bound(void *threadid)
{
int i;
double result=0.0;
/* Consumo de CPU */
for (i=0; i<10000; i++)
result = result + sin(i) * tan(i) * sqrt(result);
printf("%ld: CPU intensiva terminada\n", (long)threadid);
pthread_exit(NULL);
}
void *IO_bound(void *threadid)
{
/* Simula operações de I/O, as quais levam a bloqueio */
sleep(1);
printf("%ld: E/S intensiva terminada\n", (long)threadid);
pthread_exit(NULL);
}
int main()
{
pthread_t threads[NTHREADS];
int rc;
long thId;
void *status;
for(thId=0; thId<NTHREADS; thId++)
{
if(thId%2)
rc = pthread_create(&threads[thId], NULL, CPU_bound, (void *)thId);
else
rc = pthread_create(&threads[thId], NULL, IO_bound, (void *)thId);
if (rc)
{
printf("ERRO: código de retorno de pthread_create() é %d\n", rc);
exit(-1);
}
}
for(thId=0; thId<NTHREADS; thId++)
{
rc = pthread_join(threads[thId], &status);
if (rc)
{
printf("ERRO: código de retorno de pthread_join() é %d\n", rc);
exit(-1);
}
}
printf("\n*** Tarefas concluídas ***\n");
pthread_exit(NULL);
}