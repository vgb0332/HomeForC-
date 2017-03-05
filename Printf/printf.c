/*
 * printf.c
 *
 *  Created on: Mar 23, 2016
 *      Author: Yongsuk
 */


#include <stdio.h>

void ascii()
{
	printf("ASCII code for '%c'  is: %d\n" , 'A', 'A');
	printf("ASCII code for '%c'  is: %d\n" , 'a', 'a');
	printf("ASCII code for '%c'  is: %d\n" , 'B', 'B');
	printf("ASCII code for '%c'  is: %d\n" , 'b', 'b');
	printf("ASCII code for '%c'  is: %d\n" , 'Z', 'Z');
	printf("ASCII code for '%c'  is: %d\n" , 'z', 'z');
	printf("ASCII code for '%c'  is: %d\n" , 48, '0');
	printf("ASCII code for '%c'  is: %d\n" , "\n", '\n');
	printf("ASCII code for '%c'  is: %d\n" , "\t", '\n');
	// ¼Ò½º ÄÚµå¸¦ ÀÔ·ÂÇÏ½Ã¿À.
}

void report()
{
	printf("%s\t%s\t%s\t%s", "Part Number", "Qty On Hand", "Qty On Order", "Price");
	printf("\n");
	printf(" %06d\t\t%d\t\t%d\t\t$%6.2f", 31235, 22, 86, 45.62);
	printf("\n");
	printf(" %06d\t\t%d\t\t%d\t\t$%6.2f", 321, 55, 21, 122.00);
	printf("\n");
	printf(" %06d\t\t%d\t\t%d\t\t$%6.2f", 28764, 0, 24, 0.75);
	printf("\n");
	printf(" %06d\t\t%d\t\t%d\t\t$%6.2f", 3232, 12, 0, 10.91);

	// ¼Ò½º ÄÚµå¸¦ ÀÔ·ÂÇÏ½Ã¿À.
}

void circle()
{
	float radius;

	printf("Please enter the value of the radius:");
	fflush(stdout);
	scanf("%f" , &radius);

	printf("Radius is:\t\t%7.2f", radius);
	printf("\n");
	printf("Circumference is:\t%7.2f", 2*3.14*radius);
	printf("\n");
	printf("Area is:\t\t%7.2f", 3.14*radius*radius);
	// ¼Ò½º ÄÚµå¸¦ ÀÔ·ÂÇÏ½Ã¿À.
}

void convert_year_to_sec()
{
	int year;
	printf("input the year:");
	fflush(stdout);
	scanf("%d" , &year);
	printf("%d years are %ull seconds", year, year*31556952);
	// ¼Ò½º ÄÚµå¸¦ ÀÔ·ÂÇÏ½Ã¿À.

}


int main()
{
	ascii();
	//report();
	//circle();
	//convert_year_to_sec();
	return 0;
}
