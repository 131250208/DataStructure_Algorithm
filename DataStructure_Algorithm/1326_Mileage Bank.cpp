#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int getMiles(double miles, char c) {
	int res;
	switch (c)
	{
	case 'F':res = round(miles*2.);
		break;
	case 'B':res = round(miles*1.5);
		break;
	case 'Y':
		res = round(miles);
		if (res >= 1 && res <= 500)res = 500;
		break;
	}
	return res;
}
//int main() {
//	char input[200];
//	while (true)
//	{
//		gets_s(input);
//		if (strcmp(input, "#") == 0)break;
//
//		int res = 0;
//		while (strcmp(input,"0")!=0)
//		{
//			char city1[50]; char city2[50]; double miles; char code;
//			sscanf(input, "%s %s %lf %c", &city1, &city2, &miles, &code);
//			
//			res += getMiles(miles, code);
//			gets_s(input);
//		}
//
//		printf("%d\n", res);
//	}
//	
//
//	system("pause");
//	return 0;
//}