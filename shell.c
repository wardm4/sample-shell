#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80

void parse(char *line, char **argv) {
  while (*line != '\0') {
    while (*line == ' ' || *line == '\t' || *line == '\n') {
      *line++ = '\0';
      *argv++ = line;
    }
    while (*line != '\0' && *line != ' ' && *line != 't'
	   && *line != '\n') {
      line++;
    }
  }
  *argv = '\0';
}

void execute(char **argv) {

  int status;
  pid_t pid; 
    
    //Fork a child process
    pid = fork();

    if (pid < 0) {
      printf("Error: fork failed."); //Child = 0 and Parent > 0
      exit(1);
    }
    else if (pid > 0) {
      while (wait(&status) != pid); //Waits for child process to terminate
    }
    else {
      if (execvp(*argv, argv) < 0) {
	printf("Error: did not execute\n");
	exit(1);
      }
      
    }

}

void main(void) {
  char line[1024];
  char *argv[3];

  while (1) {
    printf("sh >");
    scanf("%s", line);
    printf("\n");
    parse(line, argv);

    if (strcmp(argv[0], "exit") == 0) //Exits shell if user types exit
      {exit(0);}

    execute(argv);
  }
}
