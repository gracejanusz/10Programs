#include <stdio.h>

#define TABSPACES 8

int main() {
    int c;
    int count = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSPACES - (count % TABSPACES);
            for (int i = 0; i < spaces; ++i) {
                putchar('*');
                count++;
            }
        } else {
            putchar(c);
            if (c == '\n') {
                count = 0;
            } else {
                count++;
            }
        }
    }
    return 0;
}
