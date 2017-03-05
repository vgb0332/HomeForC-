//============================================================================
// Name        : algo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <math.h>


int M, N;
float IN[201][201] = {0};
int OUT[201][201] = {0};

bool checkHorizon(int);
bool checkVertical(int);

int main() {

	scanf("%d %d", &M, &N);
	for(int i = 0; i < M+1; i++){
		for(int j = 0; j < N+1; ++j){
			if(i == M && j == N) break;
			scanf("%f", &IN[i][j]);
		}
	}
	for(int i = 0; i < M+1; i++){
		for(int j = 0; j < N+1; ++j){
			printf("%f ", IN[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < M+1; i++){
		for(int j = 0; j < N+1; ++j){
			OUT[i][j] = (int)floor(IN[i][j]);
		}
	}
/*
	for(int i = 0; i < M+1; i++){
		for(int j = 0; j < N+1; ++j){
			printf("%d ", OUT[i][j]);
		}
		printf("\n");
	}
*/

	for(int i = 0; i < M; ++i){
		if(!checkHorizon(i)){
			for(int j = 0; j < N; ++j){
				if(!checkVertical(j)){
					OUT[i][j]++;
				}
			}
		}
	}

	for(int i = 0; i < M+1; i++){
			for(int j = 0; j < N+1; ++j){
				printf("%d ", OUT[i][j]);
			}
			printf("\n");
		}
	return 0;
}

bool checkHorizon(int x){
	int sum = 0;
	for(int j = 0; j < N; ++j){
		sum += OUT[x][j];
	}
	if(sum == OUT[x][N]) return true;
	else return false;
}

bool checkVertical(int y){
	int sum = 0;
	for(int i = 0; i < M; ++i){
		sum += OUT[i][y];
	}
	if(sum == OUT[M][y]) return true;
	else return false;
}
