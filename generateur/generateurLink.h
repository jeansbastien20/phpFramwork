#ifndef GENERATEURLINK
#define GENERATEURLINK
#include "stdlib.h"
#include "stdio.h"
#include "sys/stat.h"

void generateView(const char* name,const char* path);
char* getPath(const char* name);
void generateController(const char* name);
void generateLinkPage(const char* name){
  generateController(name);
  char* path = getPath(name);
  generateView("index",path);
  free(path);
}
void generateController(const char* name){
  char* path = "app/controllers/";//I am too lazy to count you know ^..^
  path = (char*)malloc(strlen(name)+strlen(path)+5);
  strcpy(path,"app/controllers/");
  strcat(path,name);
  strcat(path,".php");
  FILE* fichier = fopen(path,"w");
  fprintf(fichier,"<?php\n");
  fprintf(fichier,"class %s extends Controller{\n",name);
  fprintf(fichier,"\tpublic function index(){\n");
  fprintf(fichier,"\t\t$this->view('%s/index');\n",name);
  fprintf(fichier,"\t}\n");
  fprintf(fichier,"}\n");
  fclose(fichier);
  free(path);
}
char* getPath(const char* name){
  char* path = "app/views/";
  path = (char*)malloc(strlen(name)+strlen(path)+2);
  strcpy(path,"app/views/");
  strcat(path,name);
  return strcat(path,"/");
}
void generateView(const char* name,const char* path){
  mkdir(path,0777);
  char* fileName = (char*)malloc(strlen(name)+strlen(path)+5);
  strcpy(fileName,path);
  strcat(fileName,name);
  strcat(fileName,".php");
  FILE* fichier = fopen(fileName,"w");
  fprintf(fichier,"<?php\n");
  fprintf(fichier,"\tinclude_once('../app/views/_shared/header.php');\n");
  fprintf(fichier,"?>\n\n\n");
  fprintf(fichier,"<?php\n");
  fprintf(fichier,"\tinclude_once('../app/views/_shared/footer.php');\n");
  fclose(fichier);
  free(fileName);
}

#endif
