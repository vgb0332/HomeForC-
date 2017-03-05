/*
 * hi.c
 *
 *  Created on: 2017. 3. 3.
 *      Author: Yongsuk
 */

#include "stdio.h"

int main(){
	int A[] = {1,10,20,30,40,50};

	printf("%d, %d, %d, %d", A, A+2, *A+2, A[2]+2);

	return 0;
}
