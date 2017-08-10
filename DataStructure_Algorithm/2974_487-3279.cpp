/*WA
输出与样例答案一致，暂时未检查出问题
	*/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
static char mapping[] = "22233344455566677778889999";
static char num_ori[80];
static char numbers[100010][20];
static int multi[100010];
static int n;

void trans_2974_putat(int index) {
	int len = strlen(num_ori);
	int ind = 0;
	for (int i = 0; i < len; ++i) {
		if (num_ori[i] != '-') {
			if (num_ori[i] >= 'A'&&num_ori[i] <= 'Z') {
				numbers[index][ind++] = mapping[num_ori[i] - 'A'];
			}
			else
			{
				numbers[index][ind++] = num_ori[i];
			}
			if (ind == 3) {
				numbers[index][ind++] = '-';
			}
		}
	}
	numbers[index][ind] = '\0';
}
int cmp_2974(const void* s1, const void* s2) {
	char* str1 = (char*)s1;
	char* str2 = (char*)s2;
	return strcmp(str1, str2);
}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		cin >> num_ori;
//		trans_2974_putat(i);
//	}
//	qsort(numbers,n,sizeof(numbers[0]),cmp_2974);
//
//	int count = 1;
//	int index = 0;
//	for (int i = 1; i < n; ++i) {
//		if (strcmp(numbers[i], numbers[i - 1]) == 0) {
//			count++;
//		}
//		else
//		{
//			if (count >= 2) {
//				multi[index] = count;
//				memcpy(numbers[index++], numbers[i - 1],sizeof(numbers[i - 1]));
//				count = 1;
//			}
//		}
//	}
//
//	if (index == 0)cout << "No duplicates." << endl;
//	else
//	{
//		for (int i = 0; i < index; ++i) {
//			cout << numbers[i] << " " << multi[i] << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
