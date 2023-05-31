#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    char* FirstString = argv[1];
    char* SecondString = argv[2];
    int FirstLength = strlen(FirstString);
    int SecondLength = strlen(SecondString);
    char MostCommonChar;
    int CharCount= 0;
    int counter = 0;
    while (counter<FirstLength){
        int frequency = 0;
        char c = FirstString[counter]; // check every character
        for(int i = 0; i< SecondLength; i++){
            if(c == SecondString[i]){
                frequency++;
            }
        }

        if((frequency == CharCount && c < MostCommonChar) || frequency > CharCount){
            CharCount = frequency;
            MostCommonChar = c;
        }

        counter++;
    }
    printf("Most often: %c No. times: %d\n", MostCommonChar, CharCount);
    return 0;

}

