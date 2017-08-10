/*Accepted
���������4
1�����ܱ�������д��һ��-----110
2��©���˷���-1ʱ���"oop!"
3���ߵ���ʯ��ʱ��û���ж��Ƿ��Ѿ��ù�������״̬k��֪��----45
4��������֮�䴫�Ͳ��Ʋ���----119
*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

struct State_4105
{
	int i, j, state_k,layer;
	State_4105() {}
	State_4105(int ii,int jj,int kk,int ll):i(ii),j(jj),state_k(kk), layer(ll){}
};

static State_4105 group_$[15];
static int R, C, K;
static char map[210][210];
static char sign[210][210][1<<5];

bool check(int i, int j) {
	if (i >= 0 && i < R&&j >= 0 && j < C) {
		if (map[i][j] != '#')return true;
	}
	return false;
}
//�������б�ʯ��
int getNum_k(int k) {
	int temp;
	int count = 0;
	while (true)
	{
		temp = k % 2;
		if (temp == 1)++count;
		k = k / 2;
		if (k == 0)break;
	}
	return count;
}
bool have(int k,int num) {//*
	for (int i = 0; i < num; ++i)k /= 2;
	if (k % 2 == 1)return true;
	return false;
}
int bfs_4105(queue<State_4105> &que,int i_1,int j_1,int k_1,int l_1) {
	if (check(i_1, j_1)) {
		if (map[i_1][j_1] == 'E'&&getNum_k(k_1) >= K)return l_1;//��������ҵ�Eʱ���������ͷ��ز�Σ�·������

		if (map[i_1][j_1] >= '0' && map[i_1][j_1] <= '4') {//����Ǳ�ʯ
			int num_dia = map[i_1][j_1] - '0';//��ʯ����
			if(!have(k_1,num_dia))k_1 += (1 << num_dia);//�����û���ù��ñ�ʯ���ۼӱ�ʯ״̬
		}
		if (sign[i_1][j_1][k_1] == '@')return -1;//�Ѿ��߹�����-1

		//û�߹������ñ�ǣ�ѹ����в�����-1
		sign[i_1][j_1][k_1] = '@';
		que.push(State_4105(i_1, j_1, k_1, l_1));
	}
	return -1;
}
int del_group_4105() {
	cin >> R >> C >> K;

	int count_$=0;
	int i_0, j_0;
	for (int i = 0; i < R; ++i) {
		getchar();//���Ի���
		for (int j = 0; j < C; ++j) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '$')group_$[count_$++]=State_4105(i,j,0,0);
			if (map[i][j] == 'S') {
				i_0 = i;
				j_0 = j;
			}
		}
	}

	//������ϣ���ʼ����
	queue<State_4105> states;
	memset(sign, '0', sizeof(sign));

	states.push(State_4105(i_0, j_0, 0, 0));
	sign[i_0][j_0][0] = '@';

	while (!states.empty())
	{
		State_4105 st = states.front();
		states.pop();

		int l_1=st.layer+1,k_1=st.state_k;
		int res;

		int i_1 = st.i - 1, j_1 = st.j;
		res = bfs_4105(states,i_1, j_1, k_1, l_1);
		if (res != -1)return res;

		i_1 = st.i + 1, j_1 = st.j;
		res = bfs_4105(states, i_1, j_1, k_1, l_1);
		if (res != -1)return res;

		i_1 = st.i , j_1 = st.j - 1;
		res = bfs_4105(states, i_1, j_1, k_1, l_1);
		if (res != -1)return res;

		i_1 = st.i, j_1 = st.j + 1;//*ԭ����i_1 = st.i -1, j_1 = st.j + 1;
		res = bfs_4105(states, i_1, j_1, k_1, l_1);
		if (res != -1)return res;

		if (map[st.i][st.j] == '$') {//�����ǰ���Ǵ�����,����Ҫ�������ķ�֧
			for (int i = 0; i < count_$; ++i) {
				State_4105 st_i = group_$[i];
				if (sign[st_i.i][st_i.j][k_1] == '0') {//������������û�߹���ѹ�����
					sign[st_i.i][st_i.j][k_1] = '@';
					states.push(State_4105(st_i.i, st_i.j, k_1, l_1-1));//*����l_1��Ҫ����1����Ϊ���Ʋ���
				}
			}
		}
	}

	return -1;
}
//int main() {
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int res=del_group_4105();
//		if (res == -1)cout << "oop!" << endl;
//		else cout << res << endl;
//	}
//
//	system("pause");
//	return 0;
//}