/*
����Ƶ����һ��
�����ύ��run time erro

ע�⣺
�ṹ�岻����static����
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Region
{
	double left, right;
	Region(){}
	Region(double l, double r) :left(l), right(r) {
	}
};

static Region regions[1010];
static 	int n, d;
static	double right_min;//��ǰС����Ӧ���������С�Ҷ˵�
bool operator < (const Region &a, const Region &b) {
	return a.left < b.left;
}
int del_group_1328() {
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y > d)return -1;
		double dis = sqrt(d*d - y*y);
		regions[i] = Region((double)x - dis, (double)x + dis);
	}
	sort(regions, regions + n);
	
	right_min = regions[0].right;
	int num_radar = 1;

	for (int i = 1; i < n; ++i) {
		if (regions[i].left <= right_min) {
			right_min = min(right_min, regions[i].right);
		}
		else//����ǲ��ڵ�ǰ��Ĺ�����Χ�ڣ���˵���ڵ�ǰ�����С�Ҷ˵㣩
		{
			//�¿�һ���״���µ�ǰ�����С�Ҷ˵㣬��Ϊ�����Ѿ�����˵��������У�
			//���Ժ�������򲻻��ٸ�ǰ������н�����ֻ��Ҫ��ע��ǰ��
			++num_radar;
			right_min = regions[i].right;
		}
	}

	return num_radar;
}
//int main() {
//
//	int num_group = 1;
//	while (true)
//	{
//		cin >> n >> d;
//		if (n == 0 && d == 0)break;
//		int num_radar=del_group_1328();
//		cout << "Case " << num_group++ << ": " << num_radar << endl;
//	}
//	system("pause");
//	return 0;
//}