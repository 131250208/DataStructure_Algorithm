/*并查集*/

#include<iostream>
#include "MyKit.h"

#define maxsize 500
typedef struct {
	int parent;//父节点索引
	int data;//数据域
	int count=1;//集合元素个数
}Node;

Node Sets[maxsize];//存储所有集合，集合的根的父亲是-1；

void setRelation(int parent,int son) {//edge<parent,son>,带修改元素个数
	Sets[son].parent = parent;
	Sets[parent].count = Sets[parent].count + Sets[son].count;
}
//返回该节点的所有儿子
//findAncestor
int findAncestor(int element) {
	while (Sets[element].parent!=-1)
	{
		int ancestor= findAncestor(Sets[element].parent);	//（压缩路径）递归找到父节点，
		setRelation(ancestor,element);															//并修改到路径上的每
																	//一个相关节点的父节点索引上
	}

	return element;
}
//combine
void combine(int i,int j) {
	//找到两个节点的祖先
	int ancestor_i = findAncestor(i);
	int ancestor_j = findAncestor(j);

	if (Sets[ancestor_i].count>Sets[ancestor_j].count) {//如果i的元素多，则j并到i的祖先下
		setRelation(ancestor_i, j);
	}
	else												//否则i并到j祖先下
	{
		setRelation(ancestor_j, i);
	}
}


