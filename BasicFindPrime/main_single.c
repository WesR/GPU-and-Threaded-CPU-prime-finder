#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Goal: Make a prime finder with the fewest lines of code.
	  Try to make it so it can be threadded
Bonus: kinda inefficient (So GPU speedup is easy to test).
*/

#define numPrimes 1000

void printPrimes(int primes[]) {
	int pad = floor(log10(abs(primes[(numPrimes - 1)]))) + 2;

	for (int i = 0; i < numPrimes; i += 10) {
		for (int k = 0; k < 10; k++) {
			printf("% *d", pad, primes[(i + k)]);
		}
		printf("\n");
	}
}

int isPrime(int num) {
	if (num <= 1) return 0;//Checking smalls
	if (num % 2 == 0 && num > 2) return 0;//Checking evens
	for (int i = 3; i <= (num / 3); i += 2) {//Checking odds
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int primes[numPrimes];
	int checkIndex = 0;
	int primeIndex = 0;

	primes[(numPrimes - 1)] = 0;

	do{
		if (isPrime(checkIndex)) {
			//printf("%d is prime\n", checkIndex);
			primes[primeIndex] = checkIndex;
			primeIndex++;
		}
		checkIndex++;
	} while (!primes[(numPrimes - 1)]);

	printPrimes(primes);
	return 0;
}