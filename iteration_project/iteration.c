#include <stdio.h>


void gugudan()  // ������ ���
{
	int x, y; //x�� ���� ��, y�� ���� ��

	for (y = 1; y <= 9; y++)
	{
		for (x = 2; x <= 9; x++) //2��~9��
			printf("%d X %d = %d\t", x, y, x * y);
		printf("\n");
	}
}
void printTriangle()  //���� �ﰢ�� ���
{
	int n, i, j; //n�� �ﰢ���� ũ��, i,j�� �ݺ����� ���� ����
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
void printReverseTriangle() //�������ﰢ�� ���
{
	int n, i, j; //n�� �ﰢ���� ũ��, i,j�� �ݺ����� ���� ����
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
void printRealTriangle() //���ﰢ�� ���
{
	int n, i, j; //n�� �ﰢ���� ũ��, i,j�� �ݺ��� ���� ����
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
void printRealReverseTriangle() //�����ﰢ�� ���
{
	int n, i, j; //n�� �ﰢ���� ũ��, i,j�� �ݺ��� ���� ����
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
void printDiamond() //������ ����ϱ�
{
	int n, i, j; //n�� �ﰢ���� ũ��, i,j�� �ݺ��� ���� ����
	printf("Insert the size of a triangle: ");
	fflush(stdout);
	scanf("%d", &n);

	//�������� ���� ��(�߰����� ����)
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			printf(" ");
		for (j = 1; j <= i; j++)
			printf("* ");
		printf("\n");
	}

	//�������� �Ʒ��� ��(�߰� ���� �ȵ�)
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
