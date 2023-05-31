#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

const char* suits[] = {"Clubs","Diamonds","Spades","Hearts"};
const char* ranks[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

struct card {
    char rank[7];
    char suit[9];
    int value;
};

int *stack= NULL;
int DistanceFromTop = -1;
int top=0;
int *players=NULL; //track sums

void fatal(char* msg, struct card* stack, int* players){
    printf("Error: %s\n", msg);
    
    free(stack);
    free(players);
    exit(1);
}

void usage(struct card* stack, int* players){
    printf("drawfive <number of players> [list of cards]\n");
    printf("\tThe number of players must be between 2 and 10\n");
    free(stack);
    free(players);
    exit(1);
}

void push(struct card* nextCard, int numPlayers, struct card* stack, int* top, int* players) {
    if(*top == numPlayers*5){
        fatal("Stack is full!", stack, players);
    }
    stack[*top] = *nextCard;
    (*top)++;
}

struct card pop(struct card* stack, int* top, int* players) {
    if (*top == 0) {
        fatal("Stack is empty!", stack, players);
    }
    //struct card popped = stack[(*top)-1];
    (*top)--;
    return stack[*top];
}
void fillStack(int argc, char** argv, struct card* stack, int* players) {
    if (argc < 1 || argc > 52) {
        printf("Error: Invalid card index\n");
        exit(1);
    }
    int numPlayers = atoi(argv[1]);
    for (int i = 2; i < argc; i++){
        int val = (atoi(argv[i])-1) %13;
        int suit = floor(((atoi(argv[i]))-1)/13);
        struct card nextCard;
        strcpy(nextCard.suit, suits[suit]);
        strcpy(nextCard.rank, ranks[val]);
        nextCard.value = val+1;
        push(&nextCard, numPlayers, stack, &top, players);
    }
}

void fillStackWithRandomNumbers(int numPlayers, struct card* stack, int* players){
    int numCards = 5 * numPlayers;
    for (int i =0; i < numCards; i++){
        int val = (rand() % 13) +1;
        int rank = val -1;
        int suit = (rand()%4);
        struct card nextCard;
        strcpy(nextCard.suit, suits[suit]);
        strcpy(nextCard.rank, ranks[rank]);
        nextCard.value = val;
        push(&nextCard, numPlayers, stack, &top, players);
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

void showScores(int numPlayers, int* players){
    for(int i =1; i <= numPlayers; i++){
        printf("Player %d  scored: %d\n", i , players[i]);
    }
}

void runGame(int numPlayers, struct card*stack, int* players){
    int currPlayer = 1;
    int currCard = 1;

    for(int i=0; i<numPlayers;i++){
        players[i]=0;
    }
    for(int i=1; i<5*numPlayers; i++){
        struct card val = pop(stack, &top, players);
        printf("Players %d draws %s of %s with value %d as %d of 5 cards\n", currPlayer, val.rank, val.suit, val.value, currCard);
        players[currPlayer]+= val.value;
        if(currPlayer == numPlayers){
            currPlayer =1;
            currCard++;
        }
        else{
            currPlayer++;
        }
        if(top == 0){
            printf("\n");
            //showScores(numPlayers, players);
            break;
        }
    }
}

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

int main(int argc, char* argv[]) {
    int numPlayers = atoi(argv[1]);
    // Initialize stack and players
    struct card* stack = malloc(52 * sizeof(struct card*));
    int* players = calloc(numPlayers + 1, sizeof(int));
    for (int i =0; i <= numPlayers; i++){
        players[i]=0;
    }
    if (argc < 2) {
        usage(stack, players);
    }
    
    if (numPlayers < 1) {
        usage(stack, players);
    }
    
    if (argc == 2){//mode 1
        fillStackWithRandomNumbers(numPlayers, stack, players);
    }
    else{//mode 2
        fillStack(argc, argv, stack, players);
    }
    srand(time(NULL));
    // Run the game
    runGame(numPlayers, stack, players);
    
    // Display results
    showScores(numPlayers, players);
    showWinners(numPlayers);
    
    free(stack);
    free(players);
    
    return 0;
}