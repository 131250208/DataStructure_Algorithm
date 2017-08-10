/*Accepted
错误次数：0
思路：
1、只枚举按键的第一行或列，之后的行或列就被唯一确定，所以只需要枚举（2^6或2^5次）
2、在矩阵的左上右加一行（列）全为0的边界，以简化逻辑判断
3、具体可看北大视频
*/

#include<iostream>
using namespace std;

static int state[6][8] = {};
static int press[6][8] = {};

bool guess() {
	//当第一行按键已经确定，递推出下一行按键
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j < 7; ++j) {
			press[i + 1][j] = (state[i][j] + +press[i][j]+press[i - 1][j] + press[i][j - 1] + press[i][j + 1]) % 2;
		}
	}
	//判断最后一行是否全熄灭
	for (int j = 1; j < 7; ++j) {
		if ((state[5][j] + +press[5][j] + press[5 - 1][j] + press[5][j - 1] + press[5][j + 1]) % 2 == 1)return false;
	}
	return true;
}
void enumerate() {//用二进制累加来枚举第一行按键
	for (int i = 1; i < 7; ++i) {
		press[1][i] = 0;
	}
	//模拟二进制累加进位
	while (guess()==false)//只要还未出现正确的枚举，就一直进行二进制累加枚举
	{
		++press[1][1];
		//处理进位
		int c = 0,temp=0;
		for (int i = 1; i < 7; ++i) {
			temp=press[1][i] + c;
			c = temp / 2;
			press[1][i] = temp % 2;
		}
	}
}
//int main() {
//	for (int i = 1; i < 6; ++i) {
//		for (int j = 1; j < 7; ++j) {
//			cin >> state[i][j];
//		}
//	}
//	enumerate();
//	for (int i = 1; i < 6; ++i) {
//		for (int j = 1; j < 7; ++j) {
//			cout<<press[i][j]<<" ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}