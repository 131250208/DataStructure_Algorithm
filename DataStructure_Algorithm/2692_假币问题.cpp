#include<iostream>
#include<string.h>
using namespace std;

static char map[13];
void suppose(char c,int weight) {
	strcpy(map, "222222222222");
	map[c - 'A'] = weight;
}
bool check(char left[],char right[],char res[]) {
	int weight_l = 0, weight_r = 0;
	for (int i = 0; i < strlen(left); ++i)weight_l += map[left[i] - 'A'] - '0';
	for (int i = 0; i < strlen(right); ++i)weight_r += map[right[i] - 'A'] - '0';
	if (weight_l > weight_r&&strcmp(res,"up")==0
		||weight_l<weight_r&&strcmp(res,"down")==0
		||weight_l==weight_r&&strcmp(res,"even")==0) {
		return true;
	}
	return false;
}
void detail_group() {
	char left1[10]; char right1[10]; char res1[10];
	cin >> left1; cin >> right1; cin >> res1;
	char left2[10]; char right2[10]; char res2[10];
	cin >> left2; cin >> right2; cin >> res2;
	char left3[10]; char right3[10]; char res3[10];
	cin >> left3; cin >> right3; cin >> res3;

	for (int i = 0; i < 12; ++i) {//枚举假设---轻
		char c = (char)(i + 'A');
		suppose(c,1);//假设c是轻假币
		//有一个输入不符合假设即可跳过进行下一个假设
		if (check(left1, right1, res1) == false)continue;
		if (check(left2, right2, res2) == false)continue;
		if (check(left3, right3, res3) == false)continue;

		cout << c << " is the counterfeit coin and it is light." << endl;
		return;
	}

	for (int i = 0; i < 12; ++i) {//枚举假设---重
		char c = (char)(i + 'A');
		suppose(c, 3);//假设c是重假币
					  //有一个输入不符合假设即可跳过进行下一个假设
		if (check(left1, right1, res1) == false)continue;
		if (check(left2, right2, res2) == false)continue;
		if (check(left3, right3, res3) == false)continue;

		cout << c << " is the counterfeit coin and it is heavy." << endl;
		return;
	}
}
//int main() {
//	int group = 0;
//	cin >> group;
//	for (int i = 0; i < group;++i) {
//		detail_group();
//	}
//	system("pause");
//	return 0;
//}