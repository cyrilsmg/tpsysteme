#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main( int argc, char ** argv )
{

 /* create the pipe */
 int pfd[2];
 if (pipe(pfd) == -1){
  printf("pipe failed\n");
  exit(-1);
 }
 /* create the child */
 int pid,pid2;
 if ((pid = fork()) < 0){
  printf("fork failed\n");
  exit(-2);
  }

 if (pid == 0){
  /* child */
  close(pfd[1]); /* close the unused write side */
  dup2(pfd[0], 0); /* connect the read side with stdin */
  close(pfd[0]); /* close the read side */
  /* execute the process (wc command) */

   execlp("wc", "wc", NULL);
  printf("wc failed"); /* if execlp returns, it's an error */
  }
 else
  {
  /* parent */
  pid2=fork();
  if(pid2 == 0)
  {
   close(pfd[0]); /* close the unused read side */
   dup2(pfd[1], 1); /* connect the write side with stdout */
   close(pfd[1]); /* close the write side */
   /* execute the process (cat command) */
   execlp("cat", "cat", "/etc/passwd", NULL);
   printf("cat failed"); /* if execlp returns, it's an error */
  }
  else{
			 close(pfd[0]);
			 close(pfd[1]);
   wait(NULL);
	wait(NULL);
   }
  }
return 0;
}
