#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n = 1;
  char *c = (char*)&n;

  char executablename[100];
  strcpy(executablename, argv[0] + 2);
  puts(argv[0] + 2);
  //little endian
  if (*c == 1) {
    printf("little endian");
    if (strcmp(executablename, "big") == 0) {
      printf("1");
      exit(1);
    } else {
      printf("0");
      exit(0);
    }
  }
  //big endian
  else {
    printf("big endian");
    if (strcmp(executablename, "little") == 0) {
      printf("1");
      exit(1);
    } else {
      printf("0");
      exit(0);
    }
  }
}
