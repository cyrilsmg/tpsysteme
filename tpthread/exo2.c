#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct sigaction action;

void hand(int sig){
		  if(sig == SIGINT){	 printf("\nTHE END\n"); exit(SIGINT);}
		  }

void *ajoutInt(void* arg){
int status;
int int_g;
int i1 = ((int *)arg)[0];
int i2 = ((int *)arg)[1];
int_g = i1 + i2 ;
free(arg);
printf("somme = %d\n",int_g);
pthread_exit((void*)&status);
}

void *multFloat(void* arg){
int status;
float float_g;
float f1 = ((float *)arg)[0];
float f2 = ((float *)arg)[1];
float_g = f1 * f2 ;
free(arg);
printf("multiplication = %f\n",float_g);
pthread_exit((void*)&status);
}

int main(){
int choix;
pthread_t tid1, tid2;
action.sa_handler = hand;

printf("if ajoutInt then 0 if multFloat then 1\n");
scanf("%d",&choix);
if(choix == 0){
    int *argi=(int*)malloc(2*sizeof(int));
    scanf("%d",&argi[0]);
    scanf("%d",&argi[1]);
    pthread_create(&tid1,NULL,ajoutInt,(void *)argi);
    pthread_join(tid1,NULL);}

if(choix == 1){
    float *argf=(float*)malloc(2*sizeof(float));
    scanf("%f",&argf[0]);
    scanf("%f",&argf[1]);
    pthread_create(&tid2,NULL,multFloat,argf);
    pthread_join(tid2,NULL);}

sigaction(SIGINT, &action, NULL);
while(1) sleep(1);
return 0;
}
