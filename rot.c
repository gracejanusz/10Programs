#include <stdio.h>
#include <stdlib.h>

char shiftletter(char letter, int shift) {
    if (letter >= 'a' && letter <= 'z') {
        return 'a' + (letter - 'a' + shift) % 26;
    } else if (letter >= 'A' && letter <= 'Z') {
        return 'A' + (letter - 'A' + shift) % 26;
    } else {
        return letter;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid input. Please provide a shift value.\n");
        return 1;
    }

    int shift = atoi(argv[1]);

    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != EOF) {
        putchar(shiftletter(c, shift));
    }

    return 0;
}
