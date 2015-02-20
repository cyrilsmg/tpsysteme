#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

pid_t fils1;
int somme;
int status;

struct sigaction action;
struct sigaction action1;

void hand(int sig){
    if(sig == SIGQUIT){
        printf("\nSIGQUIT\n"); 
        kill(fils1,SIGUSR1);
        wait(&status);
        printf("status=%d\n",WEXITSTATUS(status));
        exit(SIGQUIT);
        }}

void handfils(int sig){
     if(sig == SIGQUIT) {}
     else{ 
        printf("\nsomme = %d\n",somme);
        exit(SIGQUIT);
        }}	    

int main(void)
{
 int rand(void);
 srand(time(NULL));
 
 fils1=fork();
 if (fils1 == 0){
   somme = 0;
   action1.sa_handler = handfils;
   sigaction(SIGUSR1, &action1, NULL); 
   sigaction(SIGQUIT, &action1, NULL); 
   while(1){
   somme += (rand() % 10);
   sleep(1);
   }}
 else{     
      action.sa_handler = hand;
      sigaction(SIGQUIT, &action, NULL); 
      while(1) sleep(1) ;     
  }
  return 0;
}
