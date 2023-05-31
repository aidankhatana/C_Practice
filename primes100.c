#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int PrimeCounter = 0;
int PotentialPrime = 2;
bool PrimeCheck(int PotentialPrime) { // Function declaration & definition
    int factor;
    for (factor=2; factor < PotentialPrime; factor++) {
        if (PotentialPrime % factor == 0) {
            return false;
        }
    }
    return true;
}
int main() {
while (PrimeCounter < 100) {
    if (PrimeCheck(PotentialPrime)){
        printf( "%d\t", PotentialPrime);
        PrimeCounter++;

        if (PrimeCounter % 10 == 0){
            printf("\n");
        }
    }
    PotentialPrime = PotentialPrime +1;
}
return 0;
}
