/*
 * 201404051_Á¤¿ë¼®.c
 *
 *  Created on: 2016. 9. 22.
 *      Author: Yongsuk
 */


#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int* unionSet(int* A, int* B){
	int nA = A[0]; //size of array A(1~n)
	int nB = B[0]; //size of array B(1~n)
	int nC = nA+nB;
	//Containing array set have +1 space for storing a size
	int* C = (int*)malloc((sizeof(int))*(nC+1));
	int i, j;
	int k = 1;

	//Copying all elements in A to C
	for(i = 1; i <= nA; i++)
		C[k++] = A[i];

	//Process B
	int check = 0;
	for(i = 1; i <= nB; i++){ //B[1] ~ B[nB]
		for(j = 1; j <= nA; j++){ //A[1] ~ A[nA]
			//if both A and B have the same element check+1
			if(B[i] == A[j]) check++;
		}
		//if there is no same element add the current element to C
		if(check == 0)
			C[k++] = B[i];
		//if not, initialize the check variable
		else
			check = 0;
	}
	//set the first element of C as the number of total elements after A U B
	nC = k-1;
	C[0] = nC;

	return C;
}


int main(){
	int A[4] = {3,1,2,3};
	int B[5] = {4,2,3,4,5};
	//Create a C pointer
	int* C;
	int i;
	//Initialize C as the unionset of A and B
	C = unionSet(A, B);
	//Print the elements in C(A U B)
	for(i = 1; i <= C[0]; i++)
		printf("%d ", C[i]);
	return 0;
}
