#include "path.h"
#include "copy.h"
#include <stdio.h>

int main(){

  char *path, *file, *base, *name, *extn;
  FILE *in = fopen("./data/in", "r");
  FILE *out = fopen("./data/out", "w");
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
      "path: %s\nfile: %s\tbase: %s\tname: %s\textn: %s\n\n",
      path, file, base, name, extn
    );

    free(base);
    if(NULL!=name)
      free(name);
  }

  free(path);
  fclose(in);
  fclose(out);

  return 0;
}


