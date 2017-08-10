/*
Accepted
���������0

˼·��
���������ǰ�����ᵽ������Ӷ���ʲô��ϵ�أ�
��������Ӿ���Ľ��Ϊ�ӵ�r�е�k�С��ӵ�i�е�j�е��Ӿ���������ʾ(ari��ʾa[r][i],���������±��1��ʼ)��
| a11 ���� a1i ����a1j ����a1n |
| a21 ���� a2i ����a2j ����a2n |
|  .     .     .    .    .     .    .   |
|  .     .     .    .    .     .    .   |
| ar1 ���� ari ����arj ����arn |
|  .     .     .    .    .     .    .   |
|  .     .     .    .    .     .    .   |
| ak1 ���� aki ����akj ����akn |
|  .     .     .    .    .     .    .   |
| an1 ���� ani ����anj ����ann |

��ô���ǽ��ӵ�r�е���k�е�ÿһ������ͬ�еļ����������Եõ�һ��һά�������£�
(ar1+����+ak1, ar2+����+ak2, ����,arn+����+akn)
�ɴ����ǿ��Կ����������ľ��Ǵ�һά���������ӶϺ����⣬���������Ѿ�������ת��Ϊ������Ѿ�����˵������ˡ�

*/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
static int n;
static int matrix[100][100];
static int a[100];//ת���Ķ�Ӧ����
static int b[100];//����������Ӷκ�Ҫ�õ�״̬����
static int state[100];//����Ϊ״̬�洢�������������Ӿ��������Ӿ����
int getSum_maxSubSeq(int start,int end) {//����Ϊ���±�
	//ת���ɶ�Ӧ����
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; ++i)//ÿ��
		for (int j = start; j <= end; ++j)//��
			a[i] += matrix[j][i];

	//������������Ӷκ�
	b[0] = a[0];
	int res_max =b[0];
	for (int i = 1; i < n; ++i) {
		b[i] = max(b[i - 1] + a[i], a[i]);
		res_max = max(res_max, b[i]);
	}
	return res_max;
}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < n; ++j)
//			cin >> matrix[i][j];
//
//	for(int i=1;i<=n;++i){//�Ծ��������(i)Ϊ״̬����������״̬���Ӿ���Ķ�Ӧ����������Ӷκ�
//		int res_max = -999999;
//		for (int j = 0; j < n - i + 1; ++j) {//j������ʼ�±�
//			res_max = max(getSum_maxSubSeq(j,j+i-1), res_max);
//		}
//		state[i - 1] = res_max;
//	}
//		
//	int res = -999999;
//	for (int i = 0; i < n; ++i) {
//		res = max(state[i], res);
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}