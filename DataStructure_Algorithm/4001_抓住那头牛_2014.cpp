//#include<iostream>
//#include<stdio.h>
//#include<queue>
//#include<string.h>
//using namespace std;
//
//struct Pos_2014
//{
//	int x, layer;
//	Pos_2014(int xx,int ll):x(xx),layer(ll){}
//};
//static queue<Pos_2014> que;
//static char sign[100010];
//static int N, K;
//bool isLegal_2014(int x) {
//	return x >= 0 && x <= 100000&&sign[x]=='0';
//}
//int next_state(queue<Pos_2014> &que,int x,int l) {
//	if (isLegal_2014(x)) {
//		sign[x] = '@';
//		if (x == K)return l;
//		que.push(Pos_2014(x, l));
//	}
//	return -1;
//}
//int main() {
//	scanf("%d %d", &N, &K);
//
//	if (N == K) {
//		printf("0\n");
//		return 0;
//	}
//
//	memset(sign, '0', sizeof(sign));
//	que.push(Pos_2014(N,0));
//	while (!que.empty())
//	{
//		Pos_2014 pos = que.front();
//		que.pop();
//
//		int res = next_state(que, pos.x - 1, pos.layer + 1);
//		if (res != -1) {
//			printf("%d\n", res);
//			break;
//		}
//		
//		res = next_state(que, pos.x + 1, pos.layer + 1);
//		if (res != -1) {
//			printf("%d\n", res);
//			break;
//		}
//
//		res = next_state(que, pos.x*2, pos.layer + 1);
//		if (res != -1) {
//			printf("%d\n", res);
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}