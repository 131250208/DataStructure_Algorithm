/*Accepted
���������1
pell��ÿһ����ⶼҪȡģ32767�������ǵ���������ȡ��k����ȡģ

˼·��
1����̬�滮����
2�����洢�ĵݹ�
	���洢�ĵݹ飬��Ϊ��Ҫ����״̬��ջ����ֵ�ϴ�ʱ����ջ�����˵�������ȶ�̬�滮�󣬲����ǵ�ͬ
*/
#include<iostream>
#include<string.h>
using namespace std;
static int pell[1000000];

/*��̬�滮*/
//int main() {
//	memset(pell, -1, sizeof(pell));
//	pell[1] = 1;
//	pell[2] = 2;
//	for (int k = 3; k < 1000000; ++k) {
//		pell[k] = (2 * pell[k - 1] + pell[k - 2])% 32767;
//	}
//
//	int n;
//	cin >> n;
//	int k;
//	for (int i = 0; i < n; ++i) {
//		cin >> k;
//		cout << pell[k] << endl;
//	}
//	system("pause");
//	return 0;
//}

//int recurse_pell(int k) {
//	if (pell[k] == -1)pell[k] = (2 * recurse_pell(k-1) + recurse_pell(k-2)) % 32767;
//	return pell[k];
//}
///*���洢�ĵݹ�*/
//int main() {
//	memset(pell, -1, sizeof(pell));
//	pell[1] = 1;
//	pell[2] = 2;
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		int k;
//		cin >> k;
//		cout<<recurse_pell(k)<<endl;
//	}
//	system("pause");
//	return 0;
//}