#include<iostream>
using namespace std;
//临时并查集，父结点存储结构，下标是结点号码，值为父结点号码，从1开始存储
static int set[100] = {0,1,1,1,2,2,2,7,7,7,7 };

//找祖父结点
int getAncestor(int node) {
	if (set[node] == node)return node;//如果父结点就是本身，那么就是祖父结点
	set[node] = getAncestor(set[node]);//更改指针为父结点的祖父，也就是本结点的祖父,这是一个压缩处理
	return set[node];
}
//合并
void combine_mine(int a, int b) {//a,b所在集合进行合并，b的祖父向a的祖父合并
	set[getAncestor(b)]=getAncestor(a);//b祖父的父亲改为a的祖父
}

//int main() {
//	combine_mine(6, 9);
//	for (int i = 1; i <= 10; ++i)cout << set[i] << ",";
//	system("pause");
//	return 0;
//}