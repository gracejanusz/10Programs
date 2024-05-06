#include<stdio.h>
#include<stdlib.h>

//Throws a segmentation error when runs

void compile(char *memory, int i){
  memory++;
  char *pointer = memory[i];
  
   while (*memory != "\n"){
     switch(*memory) {
     case '+':
       ++(*pointer);
       break;
     case '-':
       --(*pointer);
       break;
     case '>':
       ++pointer;
       break;
     case '<':
       --pointer;
       break;
     case '.':
       putchar(*pointer);
       break;
     case ',':
       *pointer = getchar();
       break;
     case '[':
       if (*pointer == 0) {
         int counter = 1;
         while (counter > 0){
           ++memory;
           if (*memory == '['){
             ++counter;
           }else if (*memory == ']'){
             --counter;
           }
         }
       }
       break;
       case ']':
         if (*pointer !=0){
           int counter = 1;
           while (counter>0){
             --memory;
             if (*memory == '['){
               --counter;
             }else if (*memory == ']'){
               ++counter;
             }
           }
         }
         break;
      }
       ++memory;
     }
 }


int main(){
  char code [100000];
  code[0] = 0;
  int i = 1;
  char input= ' ';
  while (scanf("%c", &input) != EOF && input != '\n') {
    code[i++]=input;
   }
  code[i] = 0;
  compile(code, i++);
  return 0;
}
