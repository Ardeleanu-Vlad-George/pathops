#include "path.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void path_to_base_and_file(char** path_to_base, char** file){
  int len, itr;//len - length, itr - iterator
  if(NULL == *path_to_base)
    return;
  len = strlen(*path_to_base);

  for(itr=len; itr>-1; itr--)
    if(itr[*path_to_base]=='/')
      break;

  itr==-1 ? (
    *file=*path_to_base,
    *path_to_base=NULL
  ) : (
    itr[*path_to_base]='\0',
    *file=*path_to_base+itr+1
  );
}

void file_to_name_and_extn(char** file_to_name, char** extn){
  int len, itr;//len - length, itr - iterator
  if(NULL == *file_to_name)
    return;
  len = strlen(*file_to_name);

  for(itr=0; itr<len; itr++) 
    if('.'!=itr[*file_to_name])
      break;
  itr++;
  for(; itr<len; itr++) 
    if('.'==itr[*file_to_name])
      break;

  
  itr==len ? (
    *extn=NULL
  ) : (
    itr[*file_to_name]='\0',
    *extn=*file_to_name+itr+1
  );
}

char** path_to_toks(char *path, int *size){
  char *name, *extn, **toks;
  int iter;//'iter' for path analyzed, 
  //this two function calls assumes that some sort of valid string 
  //is saved in path code that checks if that is the case should be 
  //added if a simple string with none of the defining elements of the 
  //other components is saved in path, then said string ends up
  //in the 'name' component
  path_to_base_and_file(&path, &name);//after this path will remain as 'base'
  file_to_name_and_extn(&name, &extn);
  *size = 0;
  if(path){
    //count the number of separators
    for(iter=0; iter<strlen(path); iter++)
      path[iter]=='/' ? (*size)++ : 0;
    //after that, add one more token, the one at the 
    //very end
    //if no separators were found, this line counts the 
    //base itself as a token, which is correct
    (*size)++;
  }
  name ? (*size)++ : 0;
  extn ? (*size)++ : 0;
  toks = (char**)calloc(*size, sizeof(char*));
  int memb;//declared for the current member of the array of tokens
  if(path){
    toks[memb++] = path;
    for(iter=1; iter<strlen(path); iter++)
      path[iter]=='/' ? (path[iter]='\0', toks[memb++]=path+iter+1) : 0;
  }

  name ? toks[memb++] = name : NULL;
  extn ? toks[memb++] = extn : NULL;

  return toks;
}
