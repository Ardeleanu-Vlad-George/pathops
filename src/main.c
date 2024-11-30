#include "path.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*   For some weird reason, C doesn't seem to have a macro that helps you find 
*   which version of the language is used, which would be really useful now
*   since the "strdup" function was introduced in C23 (check below URL)
*   https://stackoverflow.com/questions/252782/strdup-what-does-it-do-in-c
*   And a current restriction of the project is to use C99
*   To make a similar version to what would be normal to implement, use this
*   'COPY_VERSION' macro fix
*/
#define COPY_VERSION 1

#if COPY_VERSION==0

  void* clone(void* data, int size){
    void *copy = malloc(size);
    int iter;//iterator
    for(iter=0; iter<size; iter++)
      //using this form of the subscript operator for the order of operation is clearer
      iter[(char*)copy]=iter[(char*)data];
    return copy;
  }

  #define COPY(ARG) (char*)clone((void*)ARG, strlen(ARG)+1)
  #warning "Running COPY_VERSION 0"

#elif COPY_VERSION==1

  char* strdup(char* source){
    char* copycat = malloc(strlen(source)+1);
    strcpy(copycat, source);
    return copycat;
  }

  #define COPY(ARG) strdup(ARG)
  #warning "Running COPY_VERSION 1"

#else
  #error "Invalid COPY_VERSION"
#endif


int main(int argc, char* argv[]){
  if(2 != argc){
    printf("\tERR: Please give exactly one CLA argument\n");
    return -1;
  }

  char *path, *file, *base, *name, *extn;

  path = COPY(argv[1]);
  base = COPY(path);

  path_to_base_and_file(&base, &file);

  name = COPY(file);
  file_to_name_and_extn(&name, &extn);

  printf("path: %s\n", path);
  printf("file: %s\n", file);
  printf("base: %s\n", base);
  printf("name: %s\n", name);
  printf("extn: %s\n", extn);

  return 0;
}


