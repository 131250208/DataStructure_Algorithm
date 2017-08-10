/*Accepted
错误次数：2
原因：
1、循环变量写错----66
2、忘记考虑不能涂成全黄的输出----72
*/
#include<iostream>
using namespace std;
static int n = 0;
static int wall[16][17] = {};
static int paint[16][17] = {};
bool guess_() {
	//从paint第一行的枚举开始递推后面行
	for (int i = 1; i < n ; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			paint[i + 1][j] = (wall[i][j] + paint[i][j] + paint[i - 1][j] + paint[i][j - 1] + paint[i][j + 1]) % 2;
		}
	}
	//判断最后一行是否全黄
	for (int j = 1; j < n + 1; ++j) {
		if ((wall[n][j] + paint[n][j] + paint[n - 1][j] + paint[n][j - 1] + paint[n][j + 1]) % 2 == 1)return false;
	}
	return true;
}
int getNum_paint() {
	int count = 0;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			count += paint[i][j];
		}
	}
	return count;
}
int enumerate_() {
	int min_paint = 250;
	while (true)
	{
		if (guess_()) {
			int num_paint = getNum_paint();
			min_paint = (num_paint < min_paint) ? num_paint : min_paint;
		}
		//二进制枚举并进位
		int isOver = 1;

		++paint[1][1];
		int c = 0,temp=0;
		//进位
		for (int i = 1; i < n + 1; ++i) {
			temp = paint[1][i]+c;
			c = temp / 2;
			paint[1][i] = temp % 2;
			if (paint[1][i] == 1)isOver = 0;//只要还有任意一个数不为0，就不会结束
		}
		if (isOver)break;//重新回到全0状态，说明枚举完毕
	}
	return min_paint;
}
//int main() {
//	
//	cin >> n;
//	char wall_c[15][16];
//	for (int i = 0; i < n; ++i) {
//		cin >> wall_c[i];
//	}
//	//运用熄灯问题的解决办法，存到整型数组
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j< n; ++j) {//*原代码j<n写成i<n;
//			if (wall_c[i][j] == 'w')wall[i + 1][j + 1] = 1;//白色相当于亮着的灯，需要关（涂）
//			else if(wall_c[i][j] == 'y')wall[i + 1][j + 1] = 0;
//		}
//	}
//	//枚举并返回最少涂画次数
//	if (enumerate_() == 250)cout << "inf";//*原代码忘记判断不能涂成全黄的输出
//	else cout << enumerate_();
//	system("pause");
//	return 0;
//}