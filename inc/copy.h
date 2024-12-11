#ifndef _COPY_H_
#define _COPY_H_

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
    void *copy;
    int iter;//iterator
    if(NULL != data){
      copy = malloc(data);
      for(iter=0; iter < size; iter++)
        iter[(char*)copy] = iter[(char*)data];
      return copy;
    }
    //In order to use the subscript operator, you need the pointer 
    //to be of a real type, not 'void*', a type that points to 
    //something real, a real data type. You have chosen 'char*'
    //because of it's ease of use. Because of operator precedence
    //it's easier to make the conversion inside the subscript 
    //operator.
    return NULL;
  }

  #define COPY(ARG) (char*)clone((void*)ARG, strlen(ARG)+1)
  #warning "Running COPY_VERSION 0"

#elif COPY_VERSION==1

  char* strdup(char* source){
    char* copycat;
    if(source != NULL){
      copycat = malloc(strlen(source)+1); 
      strcpy(copycat, source);
      return copycat;
    }
    return NULL;
  }

  #define COPY(ARG) strdup(ARG)
  #warning "Running COPY_VERSION 1"

#else
  #error "Invalid COPY_VERSION"
#endif


#endif//_COPY_H_
