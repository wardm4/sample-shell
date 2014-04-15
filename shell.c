#include <stdio.h>
#include <unistd.h>

#define MAX_LINE 80

void setup(char inputBuffer[], char *args[], int *background) {
  /** fill in later */
}

int main(void) {
  char inputBuffer[MAX_LINE];
  int background;
  char *args[MAX_LINE/2 +1];
  
  while (1) {
    background = 0;
    printf(" sh ->");
    setup(inputBuffer, args, &background);

    /** Fill in later */
  }
}
