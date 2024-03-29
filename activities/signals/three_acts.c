#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/*
   Here is a sample program representing a long running process that
   might need to be aborted.

   STEP 1

   Right now ^C (Ctrl-C) kills the process but it does not run the cleanup()
   function.  Register a signal handler so that the cleanup function is
   called when you use ^C to end the process.

   STEP 2

   Use the signal mask to disable ^C while Part 2.  Don't just install a
   new empty handler - use sigprocmask.  You should reenable ^C after
   Part 2 is done.

   Uncomment part2(); in main when you ready.

   STEP 3

   We'd like to make part 3 abort (and cleanup) automatically after 4
   seconds. 
   
   Hint: Check out `man alarm` for how to do this.

   Uncomment part3(); in main when you ready.

*/

static void mask_signal(int signum)
{
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, signum);
  if(sigprocmask(SIG_BLOCK, &mask, NULL) < 0)
    perror("sigprocmask:");
}

static void unmask_signal(int signum)
{
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, signum);
  if(sigprocmask(SIG_UNBLOCK, &mask, NULL) < 0)
    perror("sigprocmask:");
}

void part1()
{
  printf("Starting slow process Part 1 of 3.  It is currently safe to abort this process with ^C.\n");
  sleep(4);
}

void part2()
{
  printf("Starting slow process Part 2 of 3.  It is NOT safe to abort/interrupt this process with ^C.\n");
  sleep(4);
}

void part3()
{
  printf("Starting slow process Part 3 of 3.  If this part takes more than 4 seconds you should abort it.\n");
  sleep(30);
}

void cleanup() {
  printf("Abort detected!  Cleaning up and exiting...");
  exit(0);
}

int main(int argc, char **argv)
{
	signal(SIGINT, cleanup);
	part1();
	mask_signal(SIGINT);
	part2();
	unmask_signal(SIGINT);
	signal(SIGALRM, cleanup);
	alarm(4);
	part3();
};
