/*Accepted
�������:2
ԭ��
1���߼��ж�ʧ��-----28
2������ʣ�����������ʱ rÿ��ѭ������-1��-----18
*/
#include<iostream>
#include<algorithm>
using namespace std;
static int area,area_min=1<<30;//��ǰ���������С�����
static int v_min[21];//��С���
static int s_min[21];//��С������
static int N, M;//���������
int getv_Max(int m, int r, int h) {//��ǰ���뾶�����߶�Ϊr,hʱʣ��m������
	int v=0;
	while (m--)
	{
		v += r*r*h;//*�����ж�Ӧ��ԭ������룺v+=r--*r--*h--;
		--r;
		--h;
	}
	return v;
}
void dfs_1190(int n, int m, int r_max, int h_max) {//���ѣ�������ʣ�������ʣ��������ò����뾶�����߶�
	if (n == 0 && m == 0) {
		area_min = min(area, area_min);
		return;
	}
	else if (n <= 0 || m == 0)return;	//*ԭ������룺else if (n <= 0 || m != 0)return;������Զû���ݹ���ȥ����Ϊm��ʼһ��>0
										//ע��ʣ��������ܼ�����������m�ǵݼ�1��һ���ᾭ��0
	
	//ͬ���߼�
	/*if (m == 0) {
		if (n)return;
		else
		{
			area_min = min(area, area_min);
			return;
		}
	}
	if (n <= 0)return;*/

	//��֦����
	if (r_max < m || h_max < m)return;//�ò����뾶��߶�С������m(���)
	if (v_min[m] > n)return;//ʣ������С����Ѿ�����ʣ�����
	if (getv_Max(m, r_max, h_max) < n)return;//ʣ���������С��ʣ�����
	if (s_min[m] + area >= area_min)return;//���Ż���֦�������ǰ���������ʣ������С����������ڵ�ǰ�Ѿ��õ�����С��������Ѿ���������ȥ��
	for (int r = r_max; r >= m; --r) {
		if (m == M)area = r*r;//ʣ�����ΪMʱ�����һ��ʱ�������ϵ���
		for (int h = h_max; h >= m; --h) {
			area += 2*r*h;
			dfs_1190(n - r*r*h, m - 1, r - 1, h - 1);//����һ�㣬ʣ��������٣�����-1����һ������뾶�����߶ȶ��ȵ�ǰ����1
			area -= 2*r*h;//����
		}
	}
}
//int main() {
//	cin >> N; cin >> M;
//
//	//�����Ӧ��������С�������С������
//	v_min[0] = 0;
//	s_min[0] = 0;
//	for (int i = 1; i <= M; ++i) {
//		v_min[i] = v_min[i - 1] + i*i*i;
//		s_min[i] = s_min[i - 1] + 2 * i*i;
//	}
//
//	if (v_min[M] > N) {
//		cout << 0 << endl;
//		return 0;
//	}
//	else if(v_min[M]==N)
//	{
//		cout << M*M+s_min[N] << endl;
//		return 0;
//	}
//
//	//����ײ����߶Ⱥ����뾶(����)
//	int h_max, r_max;
//	h_max = (N - v_min[M - 1]) / M*M+1;
//	r_max = sqrt(double(N - v_min[M - 1]) / M)+1;
//
//	//��ʼ����ǰ���������С���������������
//	area = 0;
//	area_min = 1 << 30;
//	dfs_1190(N, M, r_max, h_max);//����ײ㿪ʼ������
//
//	if (area_min == 1 << 30)cout << 0 << endl;
//	else cout << area_min << endl;
//
//	system("pause");
//	return 0;
//}