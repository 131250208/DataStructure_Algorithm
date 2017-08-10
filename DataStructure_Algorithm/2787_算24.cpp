#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;

static double input[4];
static char sign[4];
bool exist;

void recurse_2787(double sum,int num) {
	if (num == 1) {
		if (abs(sum-24.)<0.0001)exist = true;
		return;
	}
		
	for (int i = 0; i < 4; ++i) {
		if (sign[i] == '0') {
			sign[i] = '@';
			recurse_2787(sum+input[i],num-1);
			sign[i] = '0';

			sign[i] = '@';
			recurse_2787(sum - input[i], num - 1);
			sign[i] = '0';

			sign[i] = '@';
			recurse_2787(sum * input[i], num - 1);
			sign[i] = '0';

			sign[i] = '@';
			recurse_2787(sum / input[i], num - 1);
			sign[i] = '0';

			sign[i] = '@';
			recurse_2787(input[i]-sum, num - 1);
			sign[i] = '0';

			sign[i] = '@';
			recurse_2787(input[i] / sum, num - 1);
			sign[i] = '0';
		}
	}
}
//int main() {
//
//	while (true)
//	{
//		scanf("%lf %lf %lf %lf", &input[0], &input[1], &input[2], &input[3]);
//		if (input[0] == 0 && input[1] == 0 && input[2] == 0 && input[3] == 0)break;
//		memset(sign, '0', sizeof(sign));
//		exist = false;
//
//		for (int i = 0; i < 4; ++i) {
//			sign[i] = '@';
//			recurse_2787(input[i], 4);
//			sign[i] = '0';
//		}
//		if (exist)printf("YES\n");
//		else printf("NO\n");
//	}
//	system("pause");
//	return 0;
//}