#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int character;
    int numSpaces = atoi(argv[1]);
	while ((character = getchar()) != EOF) { // Loop through characters
		if (character == '\t'){ // replsce tabs for spaces
			for (int spacesAdded=0; spacesAdded< numSpaces;spacesAdded++){
                putchar(' ');
            }
		}
		else{
            putchar(character); // print every non tab character noramlly
        }
	}

	return 0;
}
