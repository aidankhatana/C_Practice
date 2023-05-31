#include <stdio.h>
#include <stdlib.h>


void replaceTabs(int numSpaces, char *Line, int i);
int main(int argc, char *argv[]){
    int numSpaces = atoi(argv[1]);
    char Line[5000];

    while(fgets(Line, sizeof(Line), stdin)!= NULL){
        int i=0;
        while (Line[i] != '\0'){
            if (Line[i] == '\t'){
                replaceTabs(numSpaces, Line, i);
            }
            i++;
        }
        printf("%s", Line);
    }
    return 0;
    
}

void replaceTabs(int numSpaces, char *Line, int i){
    int spacesNeeded = numSpaces - (i % numSpaces);
    for (int j = 0; j < spacesNeeded; j++){
        Line[i+j] = ' ';
    }
}