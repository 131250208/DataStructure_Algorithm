/*δ���
 ����Ҫ�����С����45λ
 double����8B=64bit��16��10��������
 long double 12B
 �����ɴﵽĿ��
 ����
 setprecision(n)���þ���
 */

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

double trans(char input[]) {
	int len = strlen(input);
	double res = 0.;//���ؽ��
	for (int i = 2; i < len;++i) {//��С�����ʼ��ÿһλ/8��i-1�η������ۼ�
		res += (double)(input[i] - '0') / pow(8., (double)i - 1);
	}
	return res;
}
//int main() {
//	
//	//char input[17];
//	//cin.getline(input, 17);
//
//	//cout <<input<<" [8] = "<< trans(input)<<" [10]";
//	system("pause");
//
//	return 0;
//}