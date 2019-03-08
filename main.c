#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "generateur/generateurLink.h"

int main(int argc, char *argv[]){
  if(argc > 1){
    if(!strcmp(argv[1],"-l")){
      if(argc > 2)
	generateLinkPage(argv[2]);
      else
	printf("name of file expected");
    }
    else
      printf("this argument is not valid \n");
  }
  else
    printf("phpFramwork generator doesn't accept no argument \n");
  return 0;
}
