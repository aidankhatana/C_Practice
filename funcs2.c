#include <stdio.h>
void  sum3 ( int a, int b, int c, int * sum ){
    if (sum == NULL){ //Avoid crashing
        return;
    }
    *sum = a+b+c;
}

int eachContains (char ** strings, char target, unsigned numStrings, char ** firstOffending){
    int targetCounter =0;
    for (unsigned int i = 0; i<numStrings; i++){
        targetCounter=0;
        char *str = strings[i];
        while (*str != '\0'){
            if (*str == target){
                targetCounter++;
            }
            str++;
        }
        if (targetCounter==0){
            if(firstOffending != NULL){
                *firstOffending=strings[i];
            }
            return 0;
        }
    }
    return 1;
}

int filterOut( const char* inputFilename , const char* target ,const char* outputFilename ){
    if (inputFilename == NULL || target == NULL || outputFilename == NULL) {
        return 0;
    }
    FILE* inputFile = fopen(inputFilename, "r");
    FILE* outputFile = fopen(outputFilename, "w"); 
    if(inputFile==NULL || outputFile==NULL){
        return 0;
    }
    char LineCount[100];
    while(fgets(LineCount, 100, inputFile)){ //read from input, copy to output if doesnt include target
        int targetFlag = 0;
        int i = 0;
        int j= 0;
        do{
            if (LineCount[i] == target[j]){ //loop through potential target word
                j++;
                if (target[j]=='\0'){ //checks for full target word
                    targetFlag = 1;
                    break;
                }
            }
            else{
                j=0; //reset target counter
            }
            i++;
        }
        while (LineCount[i] != '\0');
    
        if (targetFlag == 0) {
            fputs(LineCount, outputFile);
        }
    }
    fclose(outputFile);
    fclose(inputFile);
    return 1;
}