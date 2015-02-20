#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>

int main()
{
 int nPid=fork();
 switch(nPid)
 {
			case 0: 
			{
					  /* On est dans le processus fils on recouvre */
                  int fd=open("dir.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
						dup2(fd, 1);
						execlp("ls", "ls", "-la", NULL);
						
						 
						 /* Dans ce cas tu utilises un appel systeme dérivée d'execve qui
						 execlp dont le prototype est :
						 int execlp(const char* application, const char* arg);
						 il faut d'ailleurs ne pas oublier que argv[0]=application sinon ca marche pas!!
						 */
			}
			default:
			{
					  /* On est dans le processus pere*/
					   
						wait(NULL); /* On attend que le fils ait terminé l'execution */
						 
			}
 			 
 }
}
