/*
 * Cproject.c
 *
 *  Created on: May 8, 2016
 *      Author: Yongsuk
 */

#include <stdio.h>
#include <stdlib.h>

void problem7() //사용자에게 정수를 입력 받고, 박수의 개수와 만세 여부를 확인, 출력
{
	int N;
	int temp;
	int clapCount = 0; //박수 칠 횟수
	int hooray = 0;    //만세 여부

	while (1)
	{
		printf("Input the number: ");
		fflush(stdout);
		scanf("%d", &N);
		if (N > 1000000) {//1000000이상일시 프로그램종료
			printf("Out of range. Closing program\n");
			break;
		}
		temp = N;
		while (temp != 0)
		{
			//정수의 자릿수가 3,6,9일 시 박수 횟수 +1
			if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9)
				clapCount++;
			temp = temp / 10;
		}
		if (N % 5 == 0) //정수가 5의 배수일 경우 만세
			hooray = 1;

		printf("clap: %d\n", clapCount);
		if (hooray == 0)
			printf("no hooray\n");
		else
			printf("hooray!\n");

		//박수 횟수 만세 여부 초기화
		hooray = 0;
		clapCount = 0;
	}
}
void problem8() //사용자에게 정수를 입력 받고, N을 반대로 한 수와 합한 결과를 출력
{
	int N;
	int temp;
	int reverse = 0; //역수
	int sum = 0;     //합

	while(1){
		printf("Input the number: ");
		fflush(stdout);
		scanf("%d", &N);
		if(N <= 0 || N >= 1000000) //프로그램 종료 여부
		{
			printf("Invalid Input Program Closes\n");
			break;
		}
		temp = N;
		while (temp != 0)
		{
			//가장 마지막 자리부터 10의 자리를 늘려가며 역순을 구한다.
			reverse = reverse * 10 + (temp % 10);
			temp = temp / 10;
		}
		sum = N + reverse;
		printf("The sum of two numbers: %d\n", sum);
		//사용된 변수들 초기화
		sum = 0;
		reverse = 0;
	}
}
void problem9() //사용자가 입력한 이진수를 십진수로 변환
{
	unsigned long long N;
	unsigned long long temp;
	int decimal = 0; //10진법 저장 변수
	int add = 1;	 //2진법 -> 10진법 변환 시 Nth 자리의 값
	int count = 0;   //N제곱승을 표현할 변수
	int i;
	while(1){
		printf("Input the number: ");
		fflush(stdout);
		scanf("%llu", &N);

		temp = N; //입력 받은 수 복사, 임시 저장

		//프로그램 종료 여부 확인1. N == 0일 시 종료
		if (N == 0) {
			printf("No binary. Program Closes\n");
			exit(1);
		}
		while (temp != 0)
		{
			//프로그램 종료 여부 확인2. 이진수가 아닐 경우
			if (temp % 10 > 1) {//N자리의 수가 2이상일 시 이진법이 X
				printf("No binary. Program Closes\n");
				exit(1);
			}
			else
			{
				if (temp % 10 == 1) { //자리 수가 1일 경우 2^count를 decimal에 합
					for (i = 0; i < count; i++)
						add *= 2;
					decimal += add;
				}
				else {				//자리 수가 0일 경우, 0;
					add = 0;
					decimal += add;
				}
			}
			//다음 자리 수를 위한 연산
			add = 1;
			count++; //자리수는 반복문이 한 번 돌때 마다 증가한다.
			temp = temp / 10;
		}
		printf("Decimal: %d\n", decimal);
		//프로그램 재사용을 위해 변수들 다시 초기화
		decimal = 0;
		count = 0;
	}
}
void problem10() //사용자에게 N을 입력받고 Palindrome 확인
{
	int N;
	int reverse = 0;
	int temp;

	while(1){
		printf("input the number: ");
		fflush(stdout);
		scanf("%d", &N);
		//프로그램 종료 여부 확인
		if(N < 0 || N > 1000000)
		{
			printf("Invalid Input. Program Closes\n");
			break;
		}

		temp = N;
		while (temp != 0)
		{
			//입력받은 수 N의 역순
			reverse = reverse * 10 + temp % 10;
			temp = temp / 10;
		}
		if (reverse == N) //역순 reverse가 N과 같다면 Palindrome
			printf("Palindrome\n");
		else
			printf("Not Palindrome\n");
		reverse = 0;
	}
}
void problem11() //사용자가 PC방 이용 시작 시간과 종료 시간, 30분당 이용 요금 입력했을 때, 시간에 대한 요금 출력
{
	int startHour, startMin; //시작 시간, 분
	int endHour, endMin;	 //종료 시간, 분
	int totalT = 0;			 //총 사용 시간
	int price;				 //30분당 이용 요금
	int totalP = 0;			 //총 요금

	while(1){
		printf("Input the starting time<hour mins>: ");
		fflush(stdout);
		scanf("%d %d", &startHour, &startMin);
		printf("Input the end time<hour mins>: ");
		fflush(stdout);
		scanf("%d %d", &endHour, &endMin);
		printf("Price per 30 mins<won>: ");
		fflush(stdout);
		scanf("%d", &price);

		//총 이용 시간을 분으로 계산
		totalT = (60 * endHour + endMin) - (60 * startHour + startMin);
		//프로그램 종료 여부: 요금, 시간이 0이하
		if (totalT <= 0 || price <= 0){
			printf("Invalid Input. Program Closes.\n");
			break;
		}

		//총 시간(분)을 30분 단위로 나누어 총 이용시간을 계산한다.
		// *주의점: 30분 이하로 사용했을 시에는 30분 이용요금 선정을 위해 총 이용시간에 30분을 더하여 게산한다.
		if (totalT % 30 == 0)
			totalP = price*(totalT / 30);
		else
			totalP = price*((totalT+30) / 30);

		printf("Total time spent: %d hour %d mins <%d mins>\n", totalT / 60, totalT % 60, totalT);
		printf("Total price: %d\n\n", totalP);
		//변수 다시 초기화
		totalT = 0;
		totalP = 0;
	}
}
void problem12() //사용자가 서기년도와 월을 입력 시, 해당 년도 원의 달력 출력
{
	int year, month;		//년, 월
	int startDay = 0 , endDay;	//시작 요일, 각 달의 요일 수
	int lunarYear = 0;		//윤년 여부
	int i = 1;
	int date = 1;

	printf("Input the year and month: ");
	fflush(stdout);
	scanf("%d %d", &year, &month);

	//그 해의 시작 날 계산
	for (i = 1; i <= year; i++) //서기 1년부터 입력 받은 해까지 윤년과 아닌 해르 구분하여 시작날을 더한다.
	{
		//**(ㅑ-1)을 한 이유: 작년이 윤년이여만 올해 시작 요일 2일 뒤로 밀린다.
		if (((i-1) % 4 == 0 && (i-1) % 100 != 0) || ((i-1) % 400 == 0 && (i -1) != 0))
			startDay += 2;
		else
			startDay += 1;
	}
	//일주일은 7일 임으로, 시작 요일 또한 지금 해까지의 모든 시작 요일을 계산한 값을 7로 나눈 나머지 값
	startDay = startDay % 7;

	//이번 년이 윤년이면 1, 아니면 0
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		lunarYear = 1;
	else
		lunarYear = 0;

	//각 달의 시작 날 확인 및 날수 확인 및 해당 달의 시작 요일 계산
	for (i = 2; i <= month; i++)
	{
		switch (i-1) {
		//4, 6, 9, 11월은 30일
		case 4:
		case 6:
		case 9:
		case 11:
			endDay = 30;
			break;
		case 2:
		//윤년인 년의 2월은 29일, 아니면 28일
			if (lunarYear)
				endDay = 29;
			else
				endDay = 28;
			break;
		//1, 3, 5, 7, 8, 10, 12월은 31일
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			endDay = 31;
			break;
		}
		//이번 달의 시작 요일은 1월부터 지금까지의 일수를 7로 나눈 나머지
		startDay += endDay;
	}
	startDay = startDay % 7;

	//입력받은 달의 요일 수 체크
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		endDay = 30;
		break;
	case 2:
		if (lunarYear)
			endDay = 29;
		else
			endDay = 28;
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		endDay = 31;
		break;
	}
	//달력 출력
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");

	for (i = 1; i <= startDay; i++)
	{
		printf("\t");
	}
	for (i; i <= (endDay + startDay); i++)
	{
		printf("%d\t", date);
		if (i % 7 == 0)
			printf("\n");
		date++;
	}
	printf("\n");
}
//Euler project
void Eproblem6() //1~100 "합의 제곱"과 "제곱의 합"의 차이
{
	int sum1 = 0, sum2 = 0;
	int i, j;

	//1~100 제곱의 합
	for (i = 1; i <= 100; i++)
		sum1 += i*i;

	//1~100 합의 제곱
	for (j = 1; j <= 100; j++)
		sum2 += j;
	sum2 = sum2 * sum2;

	//결과 출력
	printf("Answer: %d - %d = %d\n", sum2, sum1, sum2 - sum1);
}
void Eproblem7() // 10001번째 소수
{
	int i;
	int count = 0;
	int N = 2;
	while (1)
	{
		//소수를 구하는 알고리즘: 2부터 현재 수까지 나눠지는 수가 있으면 break,
		//				현재 수까지 도달하면 소수
		for (i = 2; i < N; i++)
		{
			if ((N % i) == 0)
				break;
		}
		//소수이면 count++;
		if (N == i)
			count++;
		//10001번째 소수이면 중지
		if (count == 10001)
			break;
		N++;
	}
	printf("Answer: %d\n", N);
}
void Eproblem9() //A+b+C = 1000의 피타고라스일 떄, AXBXC=?
{
	int a, b = 2, c = 3;
	/*
	for (a = 1; a < b ; a++)
	{
		for (b = 2; b < c; b++)
		{
			for (c = 3; c <= 997 ;c++)
			{
				if (a + b + c == 1000 && (a*a + b*b == c*c) && a < b && b < c) {
					printf("a:%d b:%d c:%d\n", a, b, c);
					printf("a X b X c = %d\n", a*b*c);
				}
			}
		}
	}
	*/
	for (a = 1; a > 0; a++)
	{
		for (b = 2; b < 999 - a; b++)
		{
			c = 1000 - b - a;
			if (a + b + c == 1000 && (a*a + b*b == c*c) && a < b && b < c) {
				printf("a:%d b:%d c:%d\n", a, b, c);
				printf("a X b X c = %d\n", a*b*c);
			}
		}
	}
}
void Eproblem10(){//2백만 이하 소수의 합

	int i = 2 , j;
	const int N = 2000000;
	long long sum = 0;
	while (i <= N)
	{
		for (j = 2; j < i; j++)
		{
			if ((i % j) == 0)
				break;
		}
		if (i == j) {
			//소수이면 더한다.
			sum += i;
			printf("Sum: %lld\n", sum);
		}
			i++;
	}
	printf("Answer: %lld\n", sum);
}
void Eproblem12(){//500개 이상의 약수를 갖는 가장 작은 삼각수

	int N = 0;
	int count = 0;
	int i = 1, j = 0;

	while (1)
	{
		//삼각수 구하기
		for (i = 1; i <= j; i++)
			N += i;

		printf("N: %d\n", N);

		//삼각수의 약수 개수 구하기
		for (i = 1; i <= N; i++)
			if (N % i == 0)
				count++;

		printf("count: %d\n", count);
		if (count >= 500)
			break;

		j++;
		N = 0;
		count = 0;
	}
}

int main()
{
	//problem7();
	//problem8();
	//problem9();
	//problem10();
	//problem11();
	//problem12();
	//Eproblem6();
	//Eproblem7();
	//Eproblem9();
	//Eprobelm10();
	//Eproblem12();
	return 0;
}

