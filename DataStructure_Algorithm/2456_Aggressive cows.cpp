/*Accepted
���������0
˼·��
�����С�������ת���ɶ����ж�����
1�����ֲ��Һ��ʵ�������x
	1��ȷ��x�ķ�Χ
	2�����ж��ֲ���
	3������ѭ����
			�������---right�ǽ��
			��С����---left�ǽ��
2���ؼ����жϺ���---����x��ţ�����벻С��x�����ж��Ƿ��ܹ���ţ�������꣬�ܰ�����ͷ���true��
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

static int stalls[100010];
static int n, c;
bool isOk(int x) {

	int pre = stalls[0];
	int count=c-1;

	for (int i = 1; i < n; i++)
	{
		if (stalls[i] - pre >= x) {
			pre = stalls[i];
			--count;
			if (count == 0)return true;
		}
	}

	return false;
}

//int main() {
//	
//	scanf("%d %d", &n,&c);
//
//	for (int i = 0; i < n; ++i) {
//		scanf("%d", &stalls[i]);
//	}
//
//	sort(stalls, stalls + n);
//	int dis_min = 1 << 30;//һ�����������1����30λ��2��30�η�������������1λ��1����31λ������1��ͷ�ˣ��з��ŵĸ���
//	for (int i = 1; i < n; ++i) {
//		int dis=stalls[i]-stalls[i-1];
//		dis_min = min(dis, dis_min);
//	}
//	int dis_max = stalls[n - 1] - stalls[0];
//
//	int left = dis_min,right=dis_max;
//	int mid;
//	while (left<=right)
//	{
//		mid = (left + right) / 2;
//		if (isOk(mid))left=mid+1;
//		else right = mid - 1;
//	}
//
//	printf("%d\n", right);
//
//	system("pause");
//	return 0;
//}