#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>

int main()
{
 int fils1,fils2;
 fils1=fork();
 if(fils1==0){   /* On est dans le processus fils on recouvre */
   pipe(int FD[2]);
						
						 
						 
	}
 else{  /* On est dans le processus pere*/
	wait(NULL); /* On attend que le fils ait terminé l'execution */
	printf("THE END\n");					 
	}
}
