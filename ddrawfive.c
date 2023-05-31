#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global defines go here
//#define STACKSIZE 50
//#define MAXPLAYERS 10
// global variables go here
int *stack= NULL;
int DistanceFromTop = -1;
int *players=NULL; //track sums

// write these functions

// prints an error message and exits returning an error to the OS
//
void fatal(char* msg){
    printf("Error: %s\n", msg);
    exit(1);
}

// instructs user how to use the program and exits returning an error to the os
//
void usage(){
    printf("drawfive <number of players> [list of cards]\n");
    printf("\tThe number of players must be between 2 and 10\n");
    exit(1);
}

// pushes an integer onto the stack, exits with error if the stack is full
//
void push(int val){
    DistanceFromTop++;//increment array size for pop and popp
    stack[DistanceFromTop] = val;
}

// returns an integer from the stack, exits with error if the stack is empty
//
int pop(){
    if (DistanceFromTop == -1) {
        fatal("Stack is empty!");
    }
    int val = stack[DistanceFromTop];
    DistanceFromTop--;
    return val;
}

// fills stack with parameters provided from the command line
//
void fillStack(int argc, char** argv){
    int numPlayers = atoi(argv[1]);
    if(numPlayers <2){
        usage();
    }
    for (int counter =2; counter < argc; counter++){
        int currCard = atoi(argv[counter]);
        if(currCard<1 || currCard>10){
            fatal("Invalid card value");
        }
        push(currCard);
    }
}

// fills stack with random numbers
//
void fillStackWithRandomNumbers(int numPlayers){
    int numCards = 5 * numPlayers;
    for (int counterr = 0;counterr < numCards; counterr++){
        push(rand()% 10 + 1);
    }
}

// displays the stack in a space separated list
//
void showStack(){
    printf("Stack:");
    for (int counterS = DistanceFromTop; counterS >= 0; counterS--) {
        printf(" %d", stack[counterS]);
    }
    printf("\n");
}

// displays scores for all players
//
void showScores(int numPlayers){
    for(int i =1; i <= numPlayers; i++){
        printf("Player %d  scored: %d\n", i , players[i]);
    }
}

// runs one game for the provided number of players reporting each card
// drawn by each player
//
void runGame(int numPlayers){
    int currPlayer =1;
    int cardValue;
    int currCard = 1;
    for (int i = 0; i < numPlayers*5; i++){
        cardValue=pop();
        players[currPlayer] += cardValue;
        printf("Player %d draws %d as %d of 5 cards\n", currPlayer++, cardValue, currCard);
        if (currPlayer>numPlayers){
            currPlayer =1;
            currCard++;
        }
    }
}

// computes the winning player and shows the results, pay careful
// attention to the output, the detail does matter
//
void showWinners(int numPlayers){
        int highestScore = 0;
    for (int i = 1; i <= numPlayers; i++) {
        if (players[i] > highestScore) {
            highestScore = players[i];
        }
    }
    
    int numWinners = 0;
    int *winners= NULL;
    winners = calloc(numPlayers, sizeof(int));
    
    for (int i = 1; i <= numPlayers; i++) {
        if (players[i] == highestScore) {
            winners[numWinners] = i;
            numWinners++;
        }
    }
    
    if (numWinners == 1) {
        printf("Player %d won with a score of %d\n", winners[0], highestScore);
    } else {
    printf("Players ");
    if (numWinners == 1) {
        printf("%d", winners[0]);
    } else if (numWinners == 2) {
        printf("%d and %d", winners[0], winners[1]);
    } else {
        for (int i = 0; i < numWinners; i++) {
            if (i == numWinners - 1) {
                printf("and %d", winners[i]);
            } else {
                if (i == 0) {
                    printf("%d, ", winners[i]);
                } else {
                    printf("%d, ", winners[i]);
                }
            }
        }
    }
    printf(" tied with a score of %d\n", highestScore);
}
    free(winners);
}

int main(int argc, char** argv) {
    srand(time(NULL)); //random number generator
    int numPlayers = atoi(argv[1]);
    stack = (int*) malloc(5 * numPlayers * sizeof(int));
    players = (int*) malloc((numPlayers + 1) * sizeof(int));
    if (argc == 2){//mode 1
        fillStackWithRandomNumbers(numPlayers);
    }
    else{//mode 2
        fillStack(argc, argv);
    }
    runGame(numPlayers);
    printf("\n");
    showScores(numPlayers);
    printf("\n");
    showWinners(numPlayers);
    free(stack);
    free(players);

    return 0;
}