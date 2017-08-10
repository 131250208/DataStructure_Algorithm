/*考前练习 Accepted*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
static char sign[100010];
static 	int n,k;
struct Pos
{
	int x, layer;
	Pos(int xx,int ll):x(xx),layer(ll){}
};
bool islegal(int x) {
	return x >= 0 && x <= 100000&&sign[x]=='0';
}

int go_next_step(queue<Pos> &que,int x,int l) {
	if (!islegal(x))return -1;
	if (x == k)return l;
	sign[x] = '@';
	que.push(Pos(x, l));
	return -1;
}
int catch_bull() {
	if (n == k)return 0;

	queue<Pos> que;
	memset(sign, '0', sizeof(sign));

	que.push(Pos(n, 0));
	sign[n] = '@';

	while (!que.empty())
	{
		Pos pos = que.front();
		que.pop();

		int time;
		time=go_next_step(que, pos.x - 1, pos.layer + 1);
		if (time != -1)return time;

		time=go_next_step(que, pos.x + 1, pos.layer + 1);
		if (time != -1)return time;

		time=go_next_step(que, pos.x*2, pos.layer + 1);
		if (time != -1)return time;
	}

	return -1;
}
//int main() {
//
//	scanf("%d %d", &n, &k);
//
//	int time = catch_bull();
//	printf("%d\n", time);
//
//	system("pause");
//	return 0;
//}



/*Accepted
错误次数：2
1、广度优先搜索，队列push后应该立即标记该元素已经访问过，不可出队的时候才标记------------26,40,45,50
（出队才标记可能导致相同元素多次入栈，除非结构是树而不是图，是树则可以出队才标记）
2、行走范围判断失误，应该为题设允许的最大范围，而不是农夫与牛之间的区域。-------------43,48

关注：
结构体简便的构造方法----------17
*/
//#include<iostream>
//#include<queue>
//#include<string.h>
//using namespace std;
//
//struct Step {
//	int x, layer;
//	Step(int xx,int ll):x(xx),layer(ll){}
//};
//static queue<Step> que_steps;
//static int visited[100010];
//static int n, k;
//int main() {
//
//	cin >> n >> k;
//	memset(visited, 0, sizeof(visited));
//
//	Step start = Step(n,0);
//	que_steps.push(start);
//	visited[start.x] = 1;//*
//
//	while (!que_steps.empty())
//	{
//		Step step = que_steps.front();
//		if (step.x == k) {
//			cout << step.layer << endl;
//			system("pause");
//			return 0;
//		}
//		que_steps.pop();
//
//		if (step.x - 1 >= 0 && visited[step.x - 1] != 1) {
//			que_steps.push(Step(step.x - 1, step.layer + 1));
//			visited[step.x - 1] = 1;//*
//
//		}
//		if (step.x + 1 <= 100000 && visited[step.x + 1] != 1) {//*原错误代码：step.x + 1 <= k
//			que_steps.push(Step(step.x + 1, step.layer + 1));
//			visited[step.x + 1] = 1;//*
//
//		}
//		if (step.x*2 <= 100000 && visited[step.x * 2] != 1) {//*原错误代码：step.x + 1 <= k
//			que_steps.push(Step(step.x*2, step.layer + 1));
//			visited[step.x * 2] = 1;//*
//
//		}
//
//	}
//	system("pause");
//	return 0;
//}