#include <stdio.h>

void hw5_11()
{
	int Smin,Ssec,Fmin,Fsec,Tmin,Tsec,Time,Fee,Temp;

	printf("���� �ð� �Է�<�ð� ��> : ");
	fflush(stdout);
	scanf("%d %d",&Smin,&Ssec);

	printf("���� �ð� �Է�<�ð� ��> : ");
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

	printf("30�д� �̿�ݾ�<��> : 500\n");
	Tmin = Time/60;
	Tsec = Time%60;
	printf("��ü �̿� �ð� : %d �ð� %d �� <%d��>\n",Tmin,Tsec,Time);
	printf("��� �ݾ� : %d\n",Fee);


}

int main()
{
	hw5_11();
}
