 #include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <unistd.h>
 #include <time.h>
  
 void *ajoutAlea(void* arg){
 int status;
 int somme;
 int i1 = ((int *)arg)[0];
 int i2 = ((int *)arg)[1];
 somme = i1 + i2 ;
 free(arg);
 somme += (rand() % 10);
 //envoyer le resultatat sur le tube
 pthread_exit((void*)&status);
 }
 
 void *lire(void* arg){
 }
 
 int main(){
 pthread_t tid1, tid2, tid3, tid4;
 
 int *arg1=(int*)malloc(2*sizeof(int));
 scanf("%d",&argi[0]);
 scanf("%d",&argi[1]);
 pthread_create(&tid1,NULL,ajoutInt,(void *)arg1);
 pthread_join(tid1,NULL);
 
 int *arg2=(int*)malloc(2*sizeof(int));
 scanf("%d",&argi[0]);
 scanf("%d",&argi[1]);
 pthread_create(&tid1,NULL,ajoutInt,(void *)arg2);
 pthread_join(tid1,NULL);

 int *arg3=(int*)malloc(2*sizeof(int));
 scanf("%d",&argi[0]);
 scanf("%d",&argi[1]);
 pthread_create(&tid1,NULL,ajoutInt,(void *)arg3);
pthread_join(tid1,NULL);
 
 return 0;
 }
