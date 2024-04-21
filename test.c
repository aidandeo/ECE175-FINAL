#include <string.h>
#include <stdio.h>

int main(){

    printf("test");

    return 0 ;
}

void Shuffle (card *c) {
    card j;
    card temp;
//using Fisher-Yates shuffle algorithm (looked up online) //
    for (int i = 0; i < SIZE; i++) {
        j = rand() j% (i + 1);
        temp = c[i];
        c[i] = c[j];
        c[j] = temp[j];
    }
}