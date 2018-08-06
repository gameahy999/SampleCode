#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void ChildProcess(int tag, int s)
{
   printf("ChildProcess %d begin\n", tag);
   sleep(s);
   printf("ChildProcess %d end\n", tag);

   // This call is important, else it will generate new child in child process.
   exit(0);
}

void ParentProcess()
{
   printf("ParentProcess\n");
}

int main()
{
   for (int i = 0; i < 10; i++) {
      pid_t pid = fork();

      if (pid == 0) {
         ChildProcess(i, 10);
      } else {
         ParentProcess();
      }
   }

   printf("main thread is waiting now.\n");
   sleep(100);

   return 0;
}
