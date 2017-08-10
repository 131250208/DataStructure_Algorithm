/*Accepted
���������2
ԭ��
1��©�����µ�ǰλ��---73
2����ֵ��add�������ѭ���ж��û�м����ŵ���add��ֵ���ܵ����жϽ����1,0��---71

����˼·��
��¼�����������л�����λ�ü��������������������н����������ж��Ƿ�ʱ������ٵ�һ�ã�
����ֱ�ӷ���0�����Ļ���Ϊ��ǰλ�ã���ȥ�ƶ��Ͳ�ժʱ�䲢�ۼ��ϻ�������
�ж��Ƿ�ʱ�䵽��һ���������Ļ�����һ�õĻ������ۼ��ϣ�����λ�á�

ע�⣺
1���ж�ʱ���Ƿ��㹻ʱ�����ǣ��ƶ�ʱ��+��ժʱ��+����һ�����س̵�ʱ��
2��K����ʱ��ȥ�Ĳ�������һ�õĻس�ʱ�䣬ֻ���ƶ��Ͳ�ժ
3����Ŀ�Ĳ������������⣬ȱ������1
*/
#include<iostream>
using namespace std;

typedef struct{
	int num;
	int i, j;
}Peanut;

Peanut* getNewPeanut(int num,int i,int j){
	Peanut* peanut = (Peanut*)malloc(sizeof(Peanut));
	peanut->num = num;
	peanut->i = i;
	peanut->j = j;
	return peanut;
}
//����Ҫ�õ��ıȽϺ���������
int cmp(const void *a,const void *b) {
	Peanut* a_p = (Peanut*)a;
	Peanut* b_p = (Peanut*)b;
	if (a_p->num == b_p->num)return 0;
	return (a_p->num > b_p->num) ? -1 : 1;
}
//����ӵ�ǰλ�õ���һ���Ƿ���ժ�ػ���������ܾͷ��ش˴λ����������ܷ���0
int getNum(Peanut now, Peanut next,int &K) {
	int time = abs(now.i - next.i)+abs(now.j-next.j)+1+next.i+1;//��ǰ�ƶ���Ŀ�ĵ�ʱ��+��ժʱ��+���¸�Ŀ�ķ���·�ߵ�ʱ��
	if (time <= K) {
		K -= abs(now.i - next.i) + abs(now.j - next.j) + 1;//����ժ�ɹ���ֻ���ƶ��Ͳ�ժ������س�
		return next.num;
	}
	return 0;
}
//ÿ������Ҫ���еĲ������������ɻ�õĻ�����
int getNum_Peanuts_Max() {
	int M = 0, N = 0, K = 0;
	cin >> M; cin >> N; cin >> K;
	Peanut* peanut_trees = (Peanut*)malloc(sizeof(Peanut)*M*N);
	int count = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int num = 0;
			cin >> num;
			if (num != 0) {//����л���
				peanut_trees[count] = *getNewPeanut(num, i, j);
				count++;
			}
		}
	}
	qsort(peanut_trees, count, sizeof(peanut_trees[0]), cmp);//�Լ�¼���л�����pos��������

	if ((peanut_trees[0].i + 1) * 2 + 1 > K)return 0;//�����һ��������ȥ�Ļ�
	
	Peanut pos_now = peanut_trees[0];
	int res = pos_now.num, add = 0;
	K -= pos_now.i + 2;//��ȥ��һ������ժʱ��
	for (int i = 1; i < count; ++i) {
		if ((add=getNum(pos_now, peanut_trees[i], K)) != 0) {//*
			res += add;
			pos_now = peanut_trees[i];//*
		}
		else break;
	}
	return res;
}
//int main() {
//	int group = 0;
//	cin >> group;
//	for (int i = 0; i < group; ++i)cout<<getNum_Peanuts_Max()<<endl;
//	system("pause");
//	return 0;
//}