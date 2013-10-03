#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "disemvowel.h"

#define BUFFERSIZE 100

int main (int argc, char *argv[]){

  if (argc == 1) {//Read from std in
    char buffer[BUFFERSIZE];
    char* input;
    int i = 0;
    input = calloc(BUFFERSIZE, sizeof(char));
    while (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
      input[i] = buffer[i];
      i++;
    }
    printf(input);
  } else if (argc == 2) {//Call disemvowel on file, print in terminal
  } else {//We have an input file and an output file
  }
  return 0;
}

char* disemvowel(char* str) {
  char *result;
  int length = strlen (str);
  int i;
  int count = 0;
  int tally = 0;

  for(i = 0; i < length; i++)
    if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
      count += 1;

    result = calloc(count + 1, sizeof(char));

    for(i = 0; i < length; i++)
      if(tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u'){
result[tally] = str[i];
tally += 1;
      }
    result[tally] = '\0';
  
  return result;
}
