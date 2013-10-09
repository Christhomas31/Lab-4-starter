#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#define BUFFERSIZE 1024

int main (int argc, char *argv[]){
FILE *input;
FILE *output;
switch(argc)
    {
       case 1: {//Read from std in
	 disemvowel(stdin, stdout);
          break;
       }  
	case 2: {//Read file, puts to stdout
	   input = fopen( argv[1], "r");
	   disemvowel( input, stdout);
	   break;
	}
	case 3: {//read file, put in file
	   input = fopen( argv[1], "r");
	   output = fopen( argv[2], "w");
	   disemvowel( input, output);
	   break;
	}
	default:
	   puts("Wrong params.\n");
	   exit( 0 );
   }
}


void disemvowel(FILE* input, FILE* output)
{
  char str[BUFFERSIZE];
  int length = fread(str, sizeof(char), BUFFERSIZE, input);
  char* result;
  //int length = strlen (str);
  int i;
  int count = 0;
  int tally = 0;

  for(i = 0; i < length; i++){
    if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
         count += 1;
     }
  }
  result = calloc(count + 1, sizeof(char));

    for(i = 0; i < length; i++){
      if(tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u'){
result[tally] = str[i];
tally += 1;
      }
    }
    result[tally] = '\0';
  
  fwrite(result, sizeof(char), count, output);
}
