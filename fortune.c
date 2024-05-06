#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char fortune[101];
    char selectedfortune[101];
    int numfortunes = 0;

    srand(time(NULL));
    
    while (fgets(fortune, sizeof(fortune), stdin) != NULL) {
        numfortunes++;	
        if (numfortunes == 0 || (rand() % numfortunes) == 0) {
            strcpy(selectedfortune, fortune);
        }
    }
    if (numfortunes == 0) {
        printf("No fortunes found.");
        return 1;
    }
    printf("%s", selectedfortune);
    return 0;
}
