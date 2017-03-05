/*
 * 201404051.c
 *
 *  Created on: 2016. 9. 29.
 *      Author: Yongsuk
 */

#include <stdio.h>

int num; //num to be digited
int digits[100]; //array to be stored
int nDigits; //number of digits in a number

//Print every digit stored in the array
void printDigits(){
	int i;
	printf("digits: ");
	for(i = 0; i < nDigits; i++)
		printf("%d ", digits[i]);

	printf("\n");
}

//get every digit of the number and store it in the array
void getDigits(){
	int num2 = num;
	int d, i, k=0;
	for(i = 0;;i++){

		d = num2 % 10;
		digits[k]=d; k++;
		num2 = num2 / 10;
		printf("%d  %d\n", d, num2);

		//if there no more digit to find, break
		if(num2 == 0) break;
	}
	//update nDigits
	nDigits = k;
	printf("%d \n", nDigits);
}

//Convert digits in the array to an integer number
int digitsToNum(){
	int numR=0;
	int i, mult = 1;

	//Extract lowest digit from the array
	//and convert it to an integer
	for(i=0; i< nDigits; i++){
		numR=numR+(digits[i] * mult);
		mult = mult * 10;
	}
	return numR;
}

//Without using global variables, return digit from the lowest position.
int getOneDigit(){
	static int num2 = -1; //Initialize num2 by -1 to check the first time.
	static int i = 0;
	int d;
	//If the function has been called for the first time, initialize num2 by num
	if(num2 == -1) num2 = num;
	d = num2 % 10;
	num2/= 10;

	//if there's no more digit to find, return -1
	if(d == 0 && num2 < 10) return -1;

	//Store the digit into the array
	digits[i++] = d;

	//Update nDigits
	nDigits = i;






	return d;
}
int main() {
	//1. Using getDigits()
	num = 123456;

	printf("Using getDigits() to express %d\n", num);
	getDigits();
	printDigits();
	printf("%d\n\n", digitsToNum());


	num = 76543;
	printf("Using getOneDigit() to express %d\n", num);
	printf("%d\n", getOneDigit()); //3
	printf("%d\n", getOneDigit()); //4
	printf("%d\n", getOneDigit()); //5
	printf("%d\n", getOneDigit());
	printf("%d\n", getOneDigit());
	printf("%d\n", getOneDigit());
	printf("%d\n", getOneDigit());

	printDigits();
	printf("%d", digitsToNum());

	return 0;
}
