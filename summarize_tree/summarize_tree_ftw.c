#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>


static int num_dirs, num_regular;
static int callback(const char *fpath, const struct stat *sb, int typeflag) {
 	if( typeflag == FTW_D){
		num_dirs++;
	}else{
		num_regular++;
	}
	return 0;


 // Define stuff here
   }
  //
   int main(int argc, char** argv) {
   // Check arguments and set things up
   	if (argc != 2) {
		printf ("Usage: %s <path>\n", argv[0]);
		printf ("       where <path> is the file or root of the tree you want to summarize.\n");
		return 1;
	}
	num_dirs = 0;
	num_regular = 0;
	
	ftw(argv[1], callback, 16);
	
	printf("Processed all the files from <%s>.\n", argv[1]);
	printf("There were %d directories.\n", num_dirs);
	printf("There were %d regular files.\n", num_regular);
	return 0;
   }
