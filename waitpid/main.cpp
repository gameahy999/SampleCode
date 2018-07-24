#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void ChildProcess(int tag, int s)
{
   printf("ChildProcess%d begin\n", tag);
   sleep(s);
   printf("ChildProcess%d end\n", tag);
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
   pid_t pid1 = fork();

   if (pid1 == 0) {
      ChildProcess(1, 3);
   } else {
      // ParentProcess();
      pid_t pid2 = fork();
      if (pid2 == 0) {
         ChildProcess(2, 5);
      } else {
         ParentProcess();
      }
   }

   return 0;
}

/*
 * Summary:
 *    1. waitpid(-1, NULL, 0) wait for any sub-process, it will return if one of
 *       them exit.
 *    2. if all sub-process have quited, waitpid will return ASAP.
 *    3. TODO: waitpid WNOHANG
 */
