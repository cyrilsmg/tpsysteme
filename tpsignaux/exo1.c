#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

struct sigaction action;
int nb_int = 0;

void hand(int sig){
		  if(sig == SIGINT){	 printf(MESSAGE); exit(SIGINT);
}}

main(){
		  action.sa_handler = hand;
		  sigaction(SIGINT, &action, NULL);
		  while(1) sleep(1);
}
