

/*Accepted
错误次数：3
原因：
极端情况没有考虑，n==1和m==1时按一般情况的算法会出现错误导致空指针或超时
考虑到一般情况时又想在一般情况的算法上做改进，浪费了时间
所以，以后考虑极端情况应该特殊处理，一般极端情况是个例，单独用最简便方法解决即可，如本题-------33、34
*/
#include<iostream>
using namespace std;

struct Monkey{
	int number;
	Monkey* nextMonkey;
	Monkey(){}
	Monkey(int num,Monkey* next):number(num),nextMonkey(next){}
};
Monkey* getNewMonkey(int num, Monkey* next) {
	Monkey* res = (Monkey*)malloc(sizeof(Monkey));
	res->nextMonkey = next;
	res->number = num;
	return res;
}
//创建n个猴子的linkedlist,返回head头结点
Monkey* createLink(int n) {
	Monkey* head = getNewMonkey(-1, NULL);//头结点
	Monkey* p = head;
	for (int i = 1; i <=n; ++i) {
		p->nextMonkey = getNewMonkey(i, NULL);//依次尾插猴子
		p = p->nextMonkey;//移动指针
	}
	p->nextMonkey = head->nextMonkey;//将最后一个猴子的next指向第一个猴子，形成环
	return head;
}
int getKingNum(int n ,int m) {
	if (n == 1)return 1;//*
	if (m == 1)return n;//*
	Monkey* head = createLink(n);
	Monkey* p = head;
	while (p!=p->nextMonkey)//当p的next指向本身时循环结束，说明链中只剩一个猴子
	{
		//移动m-1次，删除其后结点，即第m个
		for (int i = 0; i < m-1; ++i)p = p->nextMonkey;
		Monkey* weedout = p->nextMonkey;
		p->nextMonkey = weedout->nextMonkey;//删除
		delete(weedout);
	}
	return p->number;
}
//int main() {
//	int n = 0, m = 0;
//	while (cin>>n&&cin>>m)
//	{
//		if (n == 0 && m == 0)break;
//		cout << getKingNum(n, m)<<endl;
//	}
//	system("pause");
//	return 0;
//}