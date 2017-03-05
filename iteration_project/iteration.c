#include <stdio.h>


void gugudan()  // 구구단 출력
{
	int x, y; //x는 앞의 수, y는 뒤의 수

	for (y = 1; y <= 9; y++)
	{
		for (x = 2; x <= 9; x++) //2단~9단
			printf("%d X %d = %d\t", x, y, x * y);
		printf("\n");
	}
}
void printTriangle()  //직각 삼각형 출력
{
	int n, i, j; //n은 삼각형의 크기, i,j는 반복문을 위한 변수
	printf("Input size of a triangle: ");
	fflush(stdout);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}
void printReverseTriangle() //역직각삼각형 출력
{
	int n, i, j; //n은 삼각형의 크기, i,j는 반복문을 위한 변수
	printf("Insert the size of a triangle: ");
	fflush(stdout);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= n - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void printRealTriangle() //정삼각형 출력
{
	int n, i, j; //n은 삼각형의 크기, i,j는 반복을 위한 변수
	printf("Insert the size of a triangle: ");
	fflush(stdout);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			printf(" ");
		for (j = 1; j <= i; j++)
			printf("* ");
		printf("\n");
	}
}
void printRealReverseTriangle() //역정삼각형 출력
{
	int n, i, j; //n은 삼각형의 크기, i,j는 반복을 위한 변수
	printf("Insert the size of a triangle: ");
	fflush(stdout);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
			printf(" ");
		for (j = 0; j <= n - i; j++)
			printf("* ");
		printf("\n");
	}
}
void printDiamond() //마름모 출력하기
{
	int n, i, j; //n은 삼각형의 크기, i,j는 반복을 위한 변수
	printf("Insert the size of a triangle: ");
	fflush(stdout);
	scanf("%d", &n);

	//마름모의 윗쪽 면(중간까지 포함)
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			printf(" ");
		for (j = 1; j <= i; j++)
			printf("* ");
		printf("\n");
	}

	//마름모의 아랫쪽 면(중간 포함 안됨)
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= i; j++)
			printf(" ");
		for (j = 0; j <= n - 1 - i; j++)
			printf("* ");

		printf("\n");
	}
}



int main()
{
	while(1){
	//gugudan();
	//printTriangle();
	//printReverseTriangle();
	//printRealTriangle();
	//printRealReverseTriangle();
	printDiamond();
	}

	return 0;
}
