#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 84

typedef struct card_struct {
    int value;
    char action[15];
//each card has a spot in the array, but the value and action need to hold. 
}card;


void cardscan(card *x, FILE *in);


//*****************************************************************************************************************************//
int main(void) {

char player[4][100];
int numplayers = 2;
card CARD[SIZE];
char filename[100];

printf("***** Welcome to the Game of Trains ****\n");

printf("Enter the name of the file of cards:\n"); //gets the file that has the cards and abilities //
printf("(Text file must follow format: 'Card#' 'Ability' 'next line')\n");
scanf("%s", filename);
FILE*cardFile = fopen(filename, "r");

if (fopen(filename, "r")== NULL) {
    printf("This file could not be successfully opened.");
    return 1;
}

for (int i = 0; i < SIZE; i++) { //assigns a card 'i' a number and ability to a card from the given list//
cardscan(&CARD[i], cardFile);
}
int p = 0;
while (p == 0) {
    printf("How many players are playing?(2-4):");
    scanf("%d", &numplayers);
    if (numplayers < 2 || numplayers > 4) {
        printf("Cannot play with %d player(s). Please re-enter number of players.\n", numplayers);
    }
    if (numplayers>=2 && numplayers <=4) {
        p = 1;
    }
}

for (int i = 0; i < numplayers; i++) { //allows players to have usernames//
    printf("Enter player %d name:", i + 1);
    scanf("%s", player[i]);
}

//Deal seven (7) cards to each player. Sort each player’s hand in descending order (highest card first).
//Player 1 draws one card and replaces one card in their train with it.  The replaced card goes into the face up card row.
//Player 2 draws two cards and discards one to the discard pile (face down).  Player 2 then plays the other card, replacing a card in their train with it.  The replaced card goes into the face up card row.
//If playing, the third and fourth players start with 3 cards and discard two of them, and plays the last one, following the same process as above.


return 0;
}


void cardscan(card *x, FILE *in) {
    fscanf(in, "%d", &x->value);
    fscanf(in, "%s", x->action);
}