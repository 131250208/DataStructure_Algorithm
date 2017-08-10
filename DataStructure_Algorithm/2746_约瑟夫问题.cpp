

/*Accepted
���������3
ԭ��
�������û�п��ǣ�n==1��m==1ʱ��һ��������㷨����ִ����¿�ָ���ʱ
���ǵ�һ�����ʱ������һ��������㷨�����Ľ����˷���ʱ��
���ԣ��Ժ��Ǽ������Ӧ�����⴦��һ�㼫������Ǹ��������������㷽��������ɣ��籾��-------33��34
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
//����n�����ӵ�linkedlist,����headͷ���
Monkey* createLink(int n) {
	Monkey* head = getNewMonkey(-1, NULL);//ͷ���
	Monkey* p = head;
	for (int i = 1; i <=n; ++i) {
		p->nextMonkey = getNewMonkey(i, NULL);//����β�����
		p = p->nextMonkey;//�ƶ�ָ��
	}
	p->nextMonkey = head->nextMonkey;//�����һ�����ӵ�nextָ���һ�����ӣ��γɻ�
	return head;
}
int getKingNum(int n ,int m) {
	if (n == 1)return 1;//*
	if (m == 1)return n;//*
	Monkey* head = createLink(n);
	Monkey* p = head;
	while (p!=p->nextMonkey)//��p��nextָ����ʱѭ��������˵������ֻʣһ������
	{
		//�ƶ�m-1�Σ�ɾ������㣬����m��
		for (int i = 0; i < m-1; ++i)p = p->nextMonkey;
		Monkey* weedout = p->nextMonkey;
		p->nextMonkey = weedout->nextMonkey;//ɾ��
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