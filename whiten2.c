#include <stdio.h>
#include <ctype.h>


int main(){

  char  a,b;
  //if is odd
  while( (a=fgetc(stdin)) != EOF){
    if(isspace(a)){
      continue;
    }
    b = fgetc(stdin);
    if(b == EOF){
      break;
    }
    if (a != b){
     printf("%c\n", a);
  }
 }
  return 0;
}
