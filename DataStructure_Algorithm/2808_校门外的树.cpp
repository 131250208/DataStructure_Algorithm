#include<iostream>
using namespace std;


void plan_trees(int region[],int n) {
	for (int i = 0; i <=n;++i) {
		region[i] = 1;
	}
}

void del_trees(int region[],int start,int end) {
	for (int i = start; i <= end;i++) {
		if (region[i]!=0) {
			region[i] = 0;
		}
	}
}

int remain_trees(int region[],int n) {
	int count = 0;
	for (int i = 0; i <=n;++i) {
		if (region[i]==1) {
			count++;
		}
	}

	return count;
}
//
//int main() {
//	int end_region,num_regions = 0;
//	cin >> end_region;
//	cin >> num_regions;
//
//	int region[10000];
//	plan_trees(region, end_region);
//
//	for (int i = 0; i < num_regions;++i) {
//		int start, end = 0;
//		cin >> start;
//		cin >> end;
//		del_trees(region, start, end);
//	}
//
//	cout << remain_trees(region,end_region);
//
//	system("pause");
//	return 0;
//}