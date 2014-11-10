#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5
void *PrintHello(void *threadid)
{
  long tid = (long)threadid;
  printf("Olá! Sou a thread #%ld!\n", tid);
  pthread_exit(NULL);
}
int main (int argc, char *argv[])
{
 pthread_t threads[NUM_THREADS];
 int rc;
 long t;
 for(t=0; t<NUM_THREADS; t++){
  printf("main: criando thread %ld\n", t);
  rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
  if (rc){
   printf("ERRO; pthread_create() devolveu o erro %d\n", rc);
   exit(-1);
  }
 }
 for(t=0; t<NUM_THREADS; t++){
 pthread_join(threads[t], NULL);
 }
 printf("FIM DO PROGRAMA\n");
}