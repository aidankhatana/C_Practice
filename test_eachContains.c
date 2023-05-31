# include <stdio.h>
int eachContains ( char ** strings , char target ,
                    unsigned numStrings , char ** firstOffending );

int main () {
    char* strings [] = {" abcde ", " hi there jack", " apple ", " banana "}; char* firstOffending ;
    if ( eachContains ( strings , 'a', 4 , & firstOffending )) 
        printf (" AAA \n");
    else
        printf (" firstOffending : %s\n", firstOffending ); 
    
    if ( eachContains ( strings , 'b', 4 , & firstOffending ))
        printf (" BBB \n");
    else
        printf (" firstOffending : %s\n", firstOffending ); 

    if ( eachContains ( strings , 'e', 4 , & firstOffending ))
        printf (" CCC \n");
    else
         printf (" firstOffending : %s\n", firstOffending );
}