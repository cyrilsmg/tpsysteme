#include <pthread.h>
#include <stdio.h>

int globale=100;

void *ajout500(void *arg){
int status;
globale += 500;
printf("globale = %d\n",globale);
pthread_exit((void*)&status);
}

void *div2(void *arg){
int status;
globale /= 2;
printf("globale = %d\n",globale);
pthread_exit((void*)&status);
}

int main(){
pthread_t tid1, tid2;
pthread_create(&tid1,NULL,ajout500,NULL);
pthread_create(&tid2,NULL,div2,NULL);
pthread_join(tid1,NULL);
printf("tid1 est terminee\n");
pthread_join(tid2,NULL);
printf("tid2 est terminee\n");
printf("fin du prog\n");
return 0;
}
