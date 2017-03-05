#include <iostream>
#include <String.h>
using namespace std;

int main(void){
	char str[4] = "070";
	char str2[5] = {'0', '7', '0', '8' ,'\0'};
	char str3[] = "07080";
	cout << strlen(str2) << endl;
	cout << strlen(str3) << endl;
	return 0;
}
