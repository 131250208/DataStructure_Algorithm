/*Accepted
˼·����1��ʼö�����һ�����ӷֵ����������������Ƶ���һ�����ӣ�
	��������ϣ�ÿһ���������������ĵ�һ�������Ƿ��ϵ���С���������µ�һ�����ӷֵ�����ʵ����
	���Ƴ���������
*/
#include<iostream>
using namespace std;
static int n;
int check(int x) {
	for (int i = 0; i < n-1; ++i) {
		if ((x*n + 1) % (n - 1) == 0)x = (x*n + 1) / (n - 1);
		else return -1;
	}
	return x*n + 1;
}
//int main() {
//	while (true)
//	{
//		cin >> n;
//		if (n == 0)break;
//
//		int x = 1,res;
//		while (true)
//		{
//			res= check(x++);
//			if (res != -1)break;
//		}
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}