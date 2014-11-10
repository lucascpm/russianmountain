#include "LockTicket.cpp"

   void* secao_critica(void* id, void* lock) {
   	
     while (true) {
         lock.requestCS(id);
         printf("Thread-%d is in CS\n", id);
         lock.releaseCS(id);
         
         int i = 0;
         while (i<10000000000) i++;
      }
   }

   int main () {
    LockTicket lock();
     
    pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	int rc1, rc2, rc3;

	printf("iniciando...\n");
	int t=0;

	rc1 = pthread_create(&thread1,NULL,secao_critica,(void *)++t, (void *) lock);
	rc2 = pthread_create(&thread2,NULL,secao_critica,(void *)++t, lock);
	rc3 = pthread_create(&thread3,NULL,secao_critica,(void *)++t, lock);

	pthread_join(thread1, NULL);
   }
