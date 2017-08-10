#include<iostream>
#include<stdio.h>
#include<set>
#include<map>
using namespace std;
static set<int> vectors;
static map<int, int> degree;
//int main() {
//	int num_case = 0;
//	while (true)
//	{
//		int v1, v2;
//		scanf("%d %d", &v1, &v2);
//		if (v1 == -1 && v2 == -1)break;
//
//		vectors.clear();
//		degree.clear();
//
//		while (v1 != 0 || v2 != 0)
//		{
//			vectors.insert(v1);
//			vectors.insert(v2);
//
//			degree[v2]++;
//			scanf("%d %d", &v1, &v2);
//		}
//
//		int num_root = 0;
//		bool isAtree = true;
//		for (set<int>::iterator it = vectors.begin(); it != vectors.end(); ++it) {
//			if (degree[*it] > 1) {
//				isAtree = false;
//				break;
//			}
//			if (degree[*it] == 0)num_root++;
//		}
//		if (num_root != 1&&vectors.size()!=0)isAtree = false;
//
//		if (isAtree)printf("Case %d is a tree.\n", ++num_case);
//		else printf("Case %d is not a tree.\n", ++num_case);
//
//	}
//	system("pause");
//	return 0;
//}
