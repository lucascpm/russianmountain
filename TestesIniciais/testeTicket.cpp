	
		executa_regiao_critica(); // aqui est� o c�digo a ser protegido
									// de execu��o simult�nea
		proximo++; 
		
		
		
		
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_THREADS 5

int lock = 0;

//Test and Set
int ts(int *v) {
	int tmp = *v;
	*v = 1;
	return tmp;
}

void* secao_critica(void* minha_vez) {
	
	int minha_vez; // vari�vel interna ao thread n�o compartilhada.
	minha_vez = numero; numero ++; // AT�MICO !
	
	
	printf("Thread num=%d pedindo acesso\n",p);
	
	while (proximo != minha_vez) ; // espera ocupada
	
	
//---------------SC---------------------------
		int p = (int)param;
		printf("Thread num=%d na secao critica\n",p);
	
		printf("Thread num=%d rocessando secao critica\n",p);
		
		int i = 0;
		while (i<100000000) i++;
		printf("Thread num=%d fora da secao critica...%d\n",p);
//--------------------------------------------

	lock = 0;
	return p;
}

int main (int argc, char **argv) {
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	int rc1, rc2, rc3;

	printf("iniciando...\n");
	int t=0;

	rc1 = pthread_create(&thread1,NULL,secao_critica,(void *)++t);
	rc2 = pthread_create(&thread2,NULL,secao_critica,(void *)++t);
	rc3 = pthread_create(&thread3,NULL,secao_critica,(void *)++t);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	return 0;

} 
