#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
static int nums[1010];
static int len[1010];
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i)scanf("%d", &nums[i]);
//
//	
//	len[0] = nums[0];
//	int len_max = len[0];
//	for (int i = 1; i < n; ++i) {
//		int sub_len_max = 0;
//		for (int j = 0; j < i; ++j) {
//			if (nums[j] < nums[i]) {
//				sub_len_max = max(sub_len_max, len[j]);
//			}
//		}
//		len[i] = sub_len_max + nums[i];
//		len_max = max(len_max, len[i]);
//	}
//
//	printf("%d\n", len_max);
//	system("pause");
//	return 0;
//}