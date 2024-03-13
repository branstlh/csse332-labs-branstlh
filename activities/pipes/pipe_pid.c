#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * pipe_pid.c
 *
 * Task:
 * =====
 * In this exercise, we would like to child to send its process id back to its
 * parent. Yes we can get it from the return value of fork, but we'd like to
 * have a backup way for getting it as well.
 *
 * HINT 1:
 * =======
 * You might find the functions sprintf, snprintf, and atoi very helpful.
 *
 * HINT 2:
 * =======
 *  Alternatively, remember that everything is just a bunch of bytes.  How many
 *  bytes is an integer?
 */

int main(int argc, char **argv) {
  pid_t pid;
  int fd[2];
  pipe(fd);
  pid = fork();
  if(pid == 0) {
    // child, I am the writer
    close(fd[0]);
    dprintf(fd[1], "Child PID: %d", getpid());
    exit(0);
  }
  char buf[512];
  // parent, I am the reader
  close(fd[1]);
  read(fd[0], buf, 512);
  printf("parent receieved %s", buf);
  exit(0);
}

