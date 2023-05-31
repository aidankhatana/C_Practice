#include <stdio.h>
int main(void){
	int character;
	int linesCount = 0;
	int tabsCount = 0;
	int spacesCount= 0;
	int repeatedSpaces=0;

	while ((character = getchar()) != EOF) { // Loop through characters
		if (character == '\t'){ // check for tabs
			tabsCount = tabsCount +1;
			repeatedSpaces =0;
		}
		else if (character == ' '){ //check for spaces
			spacesCount = spacesCount+1;
			if(repeatedSpaces == 0){
				repeatedSpaces = repeatedSpaces +1;
			}
		}
		else if(character == '\n') { // Check for newline
			linesCount = linesCount+1;
			repeatedSpaces = 0;
		}
		
		else {
			repeatedSpaces = 0;
		}
	}
	printf("Lines : %d\nTabs : %d\nSpaces : %d\n", linesCount, tabsCount, spacesCount);

	return 0;
}