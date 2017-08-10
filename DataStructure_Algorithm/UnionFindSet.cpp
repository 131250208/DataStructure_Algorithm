/*���鼯*/

#include<iostream>
#include "MyKit.h"

#define maxsize 500
typedef struct {
	int parent;//���ڵ�����
	int data;//������
	int count=1;//����Ԫ�ظ���
}Node;

Node Sets[maxsize];//�洢���м��ϣ����ϵĸ��ĸ�����-1��

void setRelation(int parent,int son) {//edge<parent,son>,���޸�Ԫ�ظ���
	Sets[son].parent = parent;
	Sets[parent].count = Sets[parent].count + Sets[son].count;
}
//���ظýڵ�����ж���
//findAncestor
int findAncestor(int element) {
	while (Sets[element].parent!=-1)
	{
		int ancestor= findAncestor(Sets[element].parent);	//��ѹ��·�����ݹ��ҵ����ڵ㣬
		setRelation(ancestor,element);															//���޸ĵ�·���ϵ�ÿ
																	//һ����ؽڵ�ĸ��ڵ�������
	}

	return element;
}
//combine
void combine(int i,int j) {
	//�ҵ������ڵ������
	int ancestor_i = findAncestor(i);
	int ancestor_j = findAncestor(j);

	if (Sets[ancestor_i].count>Sets[ancestor_j].count) {//���i��Ԫ�ض࣬��j����i��������
		setRelation(ancestor_i, j);
	}
	else												//����i����j������
	{
		setRelation(ancestor_j, i);
	}
}


