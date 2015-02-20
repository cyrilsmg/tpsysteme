#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int int_g;
float float_g;

void *ajoutInt(void* arg1,void* arg2){
int i1 = *(int*)arg1;
int i2 = *(int*)arg2;
int_g = i1 + i2 ;
}

void *multFloat(void* arg1,void* arg2){
float f1  = *(int*)arg1;
float f2 = *(int*)arg2;
float_g = f1 + f2 ;
}

int main(){
int choix;
pthread_t tid1, tid2;
printf("if ajoutInt then 0 if multFloat then 1\n");
scanf(%d,&choix);
if(choix == 0){}
if(choix == 1){}
return 0;
}
