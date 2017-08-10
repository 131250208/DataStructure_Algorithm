/*Accepted
错误次数：2
原因：
1、漏掉更新当前位置---73
2、赋值给add的语句在循环判断里，没有加括号导致add的值接受的是判断结果（1,0）---71

解题思路：
记录矩阵中所有有花生的位置及花生数，按花生数进行降序排序，先判断是否够时间采至少第一棵，
不够直接返回0，够的话置为当前位置，减去移动和采摘时间并累加上花生数，
判断是否够时间到下一棵树，够的话将下一棵的花生数累加上，更新位置。

注意：
1、判断时间是否足够时，考虑：移动时间+采摘时间+从下一棵树回程的时间
2、K更新时减去的不包括下一棵的回程时间，只减移动和采摘
3、题目的测试数据有问题，缺少组数1
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
//快排要用到的比较函数，升序
int cmp(const void *a,const void *b) {
	Peanut* a_p = (Peanut*)a;
	Peanut* b_p = (Peanut*)b;
	if (a_p->num == b_p->num)return 0;
	return (a_p->num > b_p->num) ? -1 : 1;
}
//计算从当前位置到下一步是否能摘回花生，如果能就返回此次花生数，不能返回0
int getNum(Peanut now, Peanut next,int &K) {
	int time = abs(now.i - next.i)+abs(now.j-next.j)+1+next.i+1;//当前移动到目的的时间+采摘时间+从下个目的返回路边的时间
	if (time <= K) {
		K -= abs(now.i - next.i) + abs(now.j - next.j) + 1;//若采摘成功，只减移动和采摘，不需回程
		return next.num;
	}
	return 0;
}
//每组数据要进行的操作，计算最多可获得的花生数
int getNum_Peanuts_Max() {
	int M = 0, N = 0, K = 0;
	cin >> M; cin >> N; cin >> K;
	Peanut* peanut_trees = (Peanut*)malloc(sizeof(Peanut)*M*N);
	int count = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int num = 0;
			cin >> num;
			if (num != 0) {//如果有花生
				peanut_trees[count] = *getNewPeanut(num, i, j);
				count++;
			}
		}
	}
	qsort(peanut_trees, count, sizeof(peanut_trees[0]), cmp);//对记录的有花生的pos进行排序

	if ((peanut_trees[0].i + 1) * 2 + 1 > K)return 0;//如果第一步都出不去的话
	
	Peanut pos_now = peanut_trees[0];
	int res = pos_now.num, add = 0;
	K -= pos_now.i + 2;//减去第一步及采摘时间
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