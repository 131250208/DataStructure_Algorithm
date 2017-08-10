/*Accepted
错误次数：3
1、超时，直接模拟加密K次会有多余的循环，需要计算出各个字母对应位置的循环周期，然后取模得到的数用来作为加密次数
2、循环嵌套用了相同的变量i
3、输出格式错误，每块后有一空行

关注：
1、读取一行字符串，不够指定长的用空格补齐的写法
		memset(text, ' ', n);//先用空格填满长度n
		cin.getline(text, n + 1);//读取一行
		text[strlen(text)] = ' ';//将末尾结束符去掉
2、忽略一个字符的两种写法
	cin.ignore()
	getchar();
*/
#include<iostream>
#include<string.h>
using namespace std;

static int encode_key[210];
static int encode_key_cir[210];
static char text[210];
static char code[210];
static int n;
void cal_cir() {
	for (int i = 1; i <= n; ++i) {
		int ind = i;
		int count = 0;
		while (true)
		{
			ind = encode_key[ind - 1];
			++count;
			if (ind == i)break;
		}
		encode_key_cir[i-1] = count;
	}
}
void encode(int k) {
	for (int i = 1; i <= n; ++i) {
		int time_enc = k%encode_key_cir[i - 1];
		int index = i;

		for(int j=0;j<time_enc;++j)
		{
			index = encode_key[index - 1];
		}
		code[index - 1] = text[i-1];
	}
}
//int main() {
//
//	while (true)
//	{
//		cin >> n;
//		if (n == 0)break;
//		//每块开始
//		for (int i = 0; i < n; ++i)cin >> encode_key[i];
//		//计算密匙的周期
//		cal_cir();
//
//		int k;
//		while (true)
//		{
//			cin >> k;
//			if (k == 0)break;
//			//读取每条text
//			getchar();
//			memset(text, ' ', n);
//			cin.getline(text, n+1);
//			text[strlen(text)] = ' ';
//
//			encode(k);
//			for (int i = 0; i < n; ++i)cout << code[i];
//			cout << endl;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}