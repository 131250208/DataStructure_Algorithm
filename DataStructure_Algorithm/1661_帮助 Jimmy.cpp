/*wrong  ��Ŀ����ͨ����δ֪ԭ���ύ����

���������1
ԭ��
1��qsort����������ṹ��ʱ�������������Ӧ��ֱ�Ӵ洢���󣬲�Ӧ�ô洢ָ�룬����ȽϺ��������
2��

˼·����̬�滮
�Ӹ߶���͵İ��ӿ�ʼ�����������ϵİ��Ӷ�checkһ���Ƿ���Դ������䵽��������ϣ��������
�Ϳ��ԴӵͰ��ӵ����Ǹ��߰��ӵ��������䵽��������ʱ��
*/
#include<iostream>
#include<algorithm>
using namespace std;

#define infinite 999999;
typedef struct {
	int x1, x2, h;
	int leftmin, rightmin;//��ƽ̨���Ҷ˵㵽��������ʱ��
}Platform;

Platform plats[1000];
static int  n, x, y, dis_max;

Platform* getInstance_platform(int x1, int x2, int h) {
	Platform* res = (Platform*)malloc(sizeof(Platform));
	res->x1 = x1;
	res->x2 = x2;
	res->h = h;
	if (h > dis_max) {
		res->leftmin = infinite;//���ø߶�����ֵ
		res->rightmin = infinite;
	}
	else
	{
		res->leftmin = h;//���ø߶�����ֵ
		res->rightmin = h;
	}
	return res;
}

//�Ƚ�ƽ̨�߶ȵĺ���
int cmp_platform(const void* p1, const void* p2) {
	Platform* plat1 = (Platform*)p1;
	Platform* plat2 = (Platform*)p2;
	int h1 = plat1->h;
	int h2 = plat2->h;
	return (h1> h2);
}

void del_group_1661() {
	
	cin >> n; cin >> x; cin >> y; cin >> dis_max;

	int x1, x2, h;
	for (int i = 0; i < n; ++i) {
		cin >> x1; cin >> x2; cin >> h;
		plats[i]=*getInstance_platform(x1, x2, h);
	}
	//��ƽ̨����
	qsort(plats, n, sizeof(plats[0]), cmp_platform);

	//����ƽ̨���Ҷ˵��������ʱ��
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dis = plats[j].h - plats[i].h;
			if (dis <= dis_max) {//���ȸ߶Ȳ����max
				//������˵�
				if (plats[j].x1 >= plats[i].x1&&plats[j].x1 <= plats[i].x2) {//���j����˵��������i��
					plats[j].leftmin = dis + min(plats[j].x1-plats[i].x1+plats[i].leftmin, plats[i].x2-plats[j].x1+plats[i].rightmin);
				}
				//�����Ҷ˵�
				if (plats[j].x2 >= plats[i].x1&&plats[j].x2 <= plats[i].x2) {//���j���Ҷ˵��������i��
					plats[j].rightmin = dis + min(plats[j].x2 - plats[i].x1 + plats[i].leftmin, plats[i].x2 - plats[j].x2 + plats[i].rightmin);
				}
			}
		}
	}

	//������
	for (int i = n - 1; i >= 0; --i) {
		if (x >= plats[i].x1&&x <= plats[i].x2) {
			cout << (y - plats[i].h + min(x-plats[i].x1+plats[i].leftmin,plats[i].x2-x+plats[i].rightmin))<<endl;
			break;
		}
	}
}
//int main() {
//	int group;
//	cin >> group;
//	for (int i = 0; i < group; ++i) {
//		del_group_1661();
//	}
//
//	system("pause");
//	return 0;
//}