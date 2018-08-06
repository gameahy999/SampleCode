#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void ChildProcess()
{
   printf("c=> pid: %d\n", getpid());
   printf("c=> ppid: %d\n", getppid());
   printf("ChildProcess begin\n");
   sleep(3);
   printf("ChildProcess end\n");
}

void ParentProcess()
{
   printf("p=> pid: %d\n", getpid());
   printf("ParentProcess\n");
   printf("before wait\n");
   waitpid(-1, NULL, 0);
   printf("after wait\n");
}

int main()
{
   printf("main entry pid: %d\n", getpid());

   pid_t pid = fork();

   if (pid == 0) {
      ChildProcess();
   } else {
      printf("This pid is for child: %d\n", (int) pid);
      ParentProcess();
   }

   return 0;
}

/*
 * Summary:
 *    1. fork will return twice:
 *       one for child(pid == 0), one for parent(not 0, but child's pid)
 *    2. any process can discover its own PID by calling getpid().
 */
