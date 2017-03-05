#include <stdio.h>

void hw5_11()
{
	int Smin,Ssec,Fmin,Fsec,Tmin,Tsec,Time,Fee,Temp;

	printf("시작 시간 입력<시간 분> : ");
	fflush(stdout);
	scanf("%d %d",&Smin,&Ssec);

	printf("종료 시간 입력<시간 분> : ");
	fflush(stdout);
	scanf("%d %d",&Fmin,&Fsec);

	if(Fmin-Smin<=0)
	{
		if(Fmin-Smin<0)
			return;
		else
		{
			if(Fsec-Ssec<=0)
				return;
		}
	}

	Time = ((60*Fmin)+Fsec)-((60*Smin)+Smin);
	if(Time<30)
		return;
	Temp=Time;
	while(Temp%30!=0)
	{
		Temp++;
	}
	Fee=(Temp/30)*500;

	printf("30분당 이용금액<원> : 500\n");
	Tmin = Time/60;
	Tsec = Time%60;
	printf("전체 이용 시간 : %d 시간 %d 분 <%d분>\n",Tmin,Tsec,Time);
	printf("사용 금액 : %d\n",Fee);


}

int main()
{
	hw5_11();
}
