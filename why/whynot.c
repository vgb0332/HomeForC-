/*
 * whynot.c
 *
 *  Created on: Apr 7, 2016
 *      Author: Yongsuk
 */


#include <stdio.h>

void checkCommonDivisor() //사용자에게 A,B 두 수를 입력받고 A가 B의 배수, 혹은 B가 A의 배수인지 판별
{
	int A, B;
	printf("Insert numbers A and B(A nor B cannot be 0): ");
	fflush(stdout);
	scanf("%d %d", &A, &B);

	if(A % B == 0 || B % A == 0) //A가 B로 나누어지거나, B가 A로 나누어지면 서로의 배수
		printf("YES!\n");
	else
		printf("NO!\n");
}
void checkTriangle() //사용자에게 세 변의 길이를 입력받고, 삼각형의 가능 여부를 판단
{
	int sideA, sideB, sideC;
	printf("Insert three sides A, B and C: ");
	fflush(stdout);
	scanf("%d %d %d", &sideA, &sideB, &sideC);

	//임의의 두변의 길이가 다른 한변보다 모든 경우에서 더 커야 삼각형이다.
	if(sideA < sideB+sideC && sideB < sideA+sideC && sideC < sideA+sideB)
		printf("YES!\n");
	else
		printf("NO!\n");
}
void calculateFee() //사용자에게 현재 시간과 나이를 입력받고 자유이용권 이용 요금 출력
{
	int hour, min, age;
	printf("Insert time(hour and minute(s)), and your age: ");
	fflush(stdout);
	scanf("%d %d %d", &hour, &min, &age);

	// 12세 초과 65세 미만일 경우
	if(age > 12 && age < 65)
		//오전9시 ~ 오후 5시
		if(hour > 9 && min >= 0 && hour < 18 && min < 60)
			printf("34000 won\n");
		//그 이외의 시간
		else
			printf("10000 won\n");
	// 12세 이하 65세 이상일 경우
	else
		 //오전9시 ~ 오후 5시
		if(hour > 9 && min >= 0 && hour < 18 && min < 60)
			printf("25000 won\n");
	 	 //그 이외의 시간
		else
			printf("10000 won\n");
}
void calculateTax() //사용자에게 근로소득세를 입력 받고, 근로소득세액을 출력
{
	long long income;
	long long total;

	printf("Enter your income: ");
	fflush(stdout);
	scanf("%lld" , &income);

	const int sec1 = 12000000;   //과세 표준1 1200만원
	const int sec2 = 46000000;   //과세 표준2 4600만원
	const int sec3 = 88000000;   //과세 표준3 8800만원
	const int sec4 = 150000000;  //과세 표준4 1억5000만원

	if(income  <= sec1) //과세 표준 1200만원 이하
		total=income*(0.06);
	else if(income <= sec2) //과세 표준 4600만원 이하
		total = (sec1 * 0.06) + ((income-sec1) * 0.15);
	else if(income <= sec3) //과세 표준 8800만원 이하
		total = (sec1 * 0.06) + ((sec2-sec1) * 0.15) + ((income-sec2) * 0.24);
	else if(income <= sec4) //과세 표준 1억5000만원 이하
		total = (sec1 * 0.06) + ((sec2-sec1) * 0.15) + ((sec3-sec2) * 0.24) + ((income-sec3) * 0.35);
	else if(income > sec4)  //과세 표준 1억 5000만원 초과
		total = (sec1 * 0.06) + ((sec2-sec1) * 0.15) + ((sec3-sec2) * 0.24) + ((sec4-sec3) * 0.35) + ((income-sec4) * 0.38);

	printf("Total: %lld\n", total);
}
void calculateOverlapRect() //사용자에게 두 개의 사각형의 좌표를 입력 받고, 겹치는 넓이 출력
{
	int x1,x2,x3,x4;
	int y1,y2,y3,y4;
	int width, height;
	int area;

	/*   참고로 이 프로그램은 x1<=x2, x3<=x4라는 전제조건이 깔려있다.    */
	printf("Insert two rectangles: ");
	fflush(stdout);
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

	if(x2 <= x3 ) 							//1번째 사각형과 2번째 사각형이 겹치지 않을때
		width = 0;
	else if(x1 < x3 && x3 < x2 && x2 <= x4) //1번쨰 사각형이 2번째 사각형 왼쪽에 걸칠 때
		width = x2 - x3;
	else if(x3 <= x1 && x1 < x4 && x4 < x2) //1번쨰 사각형이 2번째 사각형 오른쪽에 걸칠 때
		width = x4 - x1;
	else if(x1 <= x3 && x4 <= x2)           //1번 째 사각형 안에 2번째 사각형이 겹칠 때
		width = x4 - x3;
	else if(x3 <= x1 && x2 <= x4)			//1번째 사삭형이 2번째 사각형 안에 겹쳐질 때
		width = x2 - x1;

	//이하동문
	if(y2 <= y3)
		height = 0;
	else if(y1 < y3 && y3 < y2 && y2 <= y4)
		height = y2 - y3;
	else if(y3 <= y1 && y1 < y4 && y4 < y2)
		height = y4 - y1;
	else if(y1 <= y3 && y4 <= y2)
		height = y4 - y3;
	else if(y3 <= y1 && y2 <= y4)
			height = y2 - y1;

	area = width*height;
	printf("width: %d\n" , width);
	printf("height: %d\n" , height);
	printf("Area: %d\n" , area);
}

int main()
{

	//checkCommonDivisor();
	//checkTriangle();
	//calculateFee();
	//calculateTax();
	//calculateOverlapRect();

	return 0;
}
