#include "path.h"
#include "copy.h"
#include <stdio.h>

int main(){

  int iter, size;
  char *path, *file, *base, *name, *extn, **toks;
  FILE *in = fopen("./data/in", "r");
  if(NULL == in){
    fprintf(stderr, "Input file isn't available. Something went wrong.\n");
    return -1;
  }
  FILE *out = fopen("./data/out", "w");
  if(NULL == out){
    fprintf(stderr, "Output file isn't available. Something went wrong.\n");
    return -2;
  }
  path = (char*)calloc(101, 1);

  while(1){
    fgets(path, 101, in);
    if(feof(in))
      break;
    path[strlen(path)-1]='\0';

    base = COPY(path);
    path_to_base_and_file(&base, &file);

    name = COPY(file);
    file_to_name_and_extn(&name, &extn);

    fprintf(
      out,
      "path: %s\nfile: %s\tbase: %s\tname: %s\textn: %s\n",
      path, file, base, name, extn
    );
    toks = path_to_toks(path, &size);
    fprintf(out, "toks: {");
    for(iter=0; iter < size; iter++)
      fprintf(out, "%s%c", toks[iter], iter+1==size ? '}' : ',');

    fprintf(out, "\n\n");

    free(base);
    free(toks);
    if(NULL!=name)
      free(name);
  }

  free(path);
  fclose(in);
  fclose(out);

  return 0;
}


