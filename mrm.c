#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//not finished with this need to ask about the update method



int main() {
    int strategies[8] = {0};
    int won_last = 0;
    int repeated_move = 0;
    int won_current = 0;
    char prev;
    char current;

    while (scanf("%c", &current) != EOF) {
        int compguess = guess(current, won_last, repeated_move, won_current, strategies);
        printf("%d\n", compguess);
        update(won_last, repeated_move, won_current, strategies);
        prev = current;
    }
    return 0;
}

void update(int won_last, int repeated_move, int won_current, int strategies[]) {
    int index = 0;
    int last_repeated = 0;
    if (won_last) index += 4;
    if (repeated_move) index += 2;
    if (won_current) index += 1;
    s = strategies[index];
    last_repeated = (s>>1);
    s = repeated_move;
    strategies[index] = s<<1;
    if(last_repeated == repeated_move) strategies[index]++; 
}

int guess(int current, int won_last, int repeated_move, int won_current, int strategies[]) {
    int index = 0;
    if (won_last) index += 4;
    if (repeated_move) index += 2;
    if (won_current) index += 1;
    
    int s = strategies[index];

    if (s % 2 == 0) {
        return (rand() > RAND_MAX / 2) ? 1 : 0;
    } else if ((s >> 1) % 2 == 0) {
        return current;
    }
    return current ? 0 : 1;
}
