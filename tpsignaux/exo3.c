#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction action;
sigset_t ens1;
int sig;

void hand(int sig){
    if(sig == SIGINT){
        printf("\nSIGINT\n"); 
        sleep(10);
        printf("10s\n");}
}
int main()
{
sigemptyset(&ens1);
sigaddset(&ens1, SIGQUIT);
   action.sa_handler = hand;
  action.sa_mask = ens1;
   sigaction(SIGINT, &action, NULL);
    while(1) sleep(1);
}

