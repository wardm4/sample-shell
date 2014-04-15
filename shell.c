#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80

int main(void) {
  char *args[MAX_LINE/2 +1];
  int should_run = 1;

  int i, upper;
  
  while (should_run) {
    printf("sh>");
    fflush(stdout);
    scanf("%s", *args);
    

    //Fork a child process

    int pid = fork();
    if (pid != 0) {
      wait(NULL); //Waits for child process to terminate
    }
    else {
      execvp(args[0], args);
    }

    /** Fill in later */
  }
}
