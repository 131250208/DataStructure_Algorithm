/*Accepted
���������1
ԭ��
�������maxlen[0]=input[0];
��ȷӦΪmaxlen[0] = 1;---------------28
��Ϊ�Ե�һ������β�����е�����������У���������������Ϊ1

˼·��
��̬�滮���ӵ�һ������ʼ�����Ƴ���ÿһ������β�����е�����������г��ȴ�������������ٴ������ҳ����ĳ������
���ƣ�����
�����5����Ϊ7�������ǰ���4�������ҳ�����С��7����ai��������ai��β������������еĳ��ȣ�
�ҳ���ĳ�����+1���õ���7�����������β������������г���
��ϸ�ο���������Ƶ�����10.3
*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
//int main() {
//	int n;
//	cin >> n;
//
//	int input[1000];
//	for (int i = 0; i < n; ++i)cin >> input[i];
//
//	int maxlen[1000];//������input[k]��β�����е������������
//	memset(maxlen, 0, sizeof(maxlen));
//	maxlen[0] = 1;
//
//	for (int k = 1; k < n; ++k) {
//		int maxlen_temp = 0;
//		for (int i = 0; i < k; ++i) {
//			if (input[i] < input[k]) {
//				maxlen_temp = max(maxlen[i], maxlen_temp);
//			}
//		}
//		maxlen[k] = maxlen_temp + 1;
//	}
//
//	int res = 0;
//	for (int i = 0; i < n; ++i) {
//		res = max(res, maxlen[i]);
//	}
//	cout << res<<endl;
//	system("pause");
//	return 0;
//}