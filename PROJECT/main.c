/*
 * main.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: Yongsuk
 */


#include "stdio.h"


int factorial(int); 	//factorial function
int power(int, int);	//power function
void printDivisors(int);//Divisor function


int main() {
	int i;
	int j;

	//Testing factorial of from 0 to 5
	for(i = 0; i <= 5; i++)
		printf("%d! = %d\n", i, factorial(i));

	printf("\n");

	//Testing power of 0 to 5 from 0 to 5
	for(i = 0; i <= 5; i++){
		for(j = 0; j <= 5; j++)
			printf("%d^%d = %d\n", i, j, power(i,j));
		printf("\n");
	}

	printf("\n");



	for(i = 1; i <= 20; i++){
		printf("Divisors of %d = ", i);
		printDivisors(i);
	}

	return 0;

}


int factorial(int n){
	//Initialize result by 1 so it doesn't mess up the calculation.
	int result = 1;
	int i;
	//from 1 to n, keep multiplying result with the number.
	for(i = 1; i <=n; i++)
		result *= i;
	return result;
}

int power(int x, int n){
	//Initialize result by 1 so it doesn't mess up the calculation.
	int result = 1;
	int i;

	//multiply x by n times.
	for(i = 0; i < n; i++)
		result *= x;
	return result;
}

void printDivisors(int x){
	int i;
	//from i, 1 to x, if x is divided by i, it's a divisor.
	for(i = 1; i <= x; i++)
		if(x%i == 0){
			//if i reaches the end, no comma should be printed at the end.
			if(i == x) printf("%d", i) ;
			else printf("%d, ", i);
		}
	printf("\n");
}
