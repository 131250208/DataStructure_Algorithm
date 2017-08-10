/*神坑题，注意输入，第一行后可能有空格可能有回车，用getchar只能get 一个，要用
cin.ignore(10,'\n');
或者下一行读取时，前面加一个空格----40\43

*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct  Edge_2012g
{
	int v1, v2, price;
	Edge_2012g() {}
	Edge_2012g(int v1,int v2,int pr):v1(v1),v2(v2),price(pr){}
};

static Edge_2012g edges[100];
static int set[30];//并查集
bool operator < (const Edge_2012g &e1, const Edge_2012g &e2) {
	return e1.price < e2.price;
}
int findAncestor_2012g(int a) {
	if (a == set[a])return a;
	set[a] = findAncestor_2012g(set[a]);
	return set[a];
}

//int main() {
//	int n;
//	while (true)
//	{
//		scanf("%d", &n);
//		if (n == 0)break;
//
//		//开始一组
//		
//		int count_edges = 0;
//		for (int i = 0; i < n - 1; ++i) {
//			char v1; int num;
//			scanf(" %c %d", &v1, &num);//*
//			for (int j = 0; j < num; ++j) {
//				char v2; int price;
//				scanf(" %c %d", &v2, &price);//*
//				edges[count_edges++] = Edge_2012g(v1 - 'A', v2 - 'A', price);
//			}
//		}
//		//排序
//		sort(edges, edges + count_edges);
//		//初始化并查集
//		for (int i = 0; i < 30; ++i)set[i] = i;
//
//		int res_price = 0;
//		for (int i = 0; i < count_edges; ++i) {
//			int v1 = edges[i].v1;
//			int v2 = edges[i].v2;
//			int a, b;
//			if ((a=findAncestor_2012g(v1)) != (b=findAncestor_2012g(v2))) {
//				res_price += edges[i].price;
//				set[a] = b;
//			}
//		}
//		printf("%d\n", res_price);
//	}
//	
//	
//	system("pause");
//	return 0;
//}