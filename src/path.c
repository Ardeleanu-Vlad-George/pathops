#include "path.h"
#include <stdio.h>
#include <string.h>

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
