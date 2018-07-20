#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void ChildProcess()
{
   printf("ChildProcess begin\n");
   sleep(3);
   printf("ChildProcess end\n");
}

void ParentProcess()
{
   printf("ParentProcess\n");
   printf("before wait\n");
   waitpid(-1, NULL, 0);
   printf("after wait\n");
}

int main()
{
   pid_t pid = fork();

   if (pid == 0) {
      ChildProcess();
   } else {
      ParentProcess();
   }

   return 0;
}
