#include <stdio.h>
#include <stdlib.h>

int mex(int n, int v[]) {
  int* frequency = (int*)calloc(n + 1, sizeof(int));
  if (frequency == NULL) {
    printf("error\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (v[i] >= 0 && v[i] < n + 1) {
      frequency[v[i]]++;
    }
  }

  int mex = 0;
  for (int i = 0; i <= n; i++) {
    if (frequency[i] == 0) {
      mex = i;
      break;
    }
  }

  free(frequency);
  return mex;
}

int main() {
  int initialsize = 1000;
  int* v = (int*)malloc(1000 * sizeof(int));
  if (v == NULL) {
    printf("error");
    return 1;
  }

  int n = 0;
  while (scanf("%d", &v[n]) != EOF) {
    n++;
    if (n >= initialsize) {
      initialsize += 1000;
      int* newv = (int*)realloc(v, initialsize * sizeof(int));
      if (newv == NULL) {
	printf("error");
	free(v);
	return 1;
      }
      v = newv;
    }
  }
  int result = mex(n, v);

  printf("minimum excluded integer is: %d\n", result);
  free(v);
  return 0;
}
