#include <stdio.h>
#include <stdlib.h>

void convertToBase(int num, int base) {
    if (num == 0)
        return;

    convertToBase(num / base, base);

    int remainder = num % base;
    if (remainder < 10)
        printf("%d", remainder);
    else
        printf("%c", 'A' + remainder - 10);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Input incorrectly formatted");
        return 1;
    }

    int base = atoi(argv[1]);

    if (base < 2 || base > 36) {
        printf("Base must be between 2 and 36.\n");
        return 1;
    }

    int num;
    while (scanf("%d", &num) != EOF) {
        convertToBase(num, base);
        printf("\n");
    }
    return 0;
}
