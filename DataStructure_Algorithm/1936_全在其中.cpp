/*Accepted
���������1
1����ʱ����s���ȴ���tʱֱ�ӷ���no����sʣ�೤�ȴ���t��ʣ�೤��ʱ������no
*/
//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//using namespace std;
//int main() {
//	char s[100010], t[100010];
//
//	while (scanf("%s %s",&s,&t)!=EOF)
//	{
//		int len_s= strlen(s), len_t= strlen(t);
//		if (len_s > len_t) {
//			printf("No\n");
//			continue;
//		}
//		int i=0, j=0;
//		while (true)
//		{
//			if (s[i] == t[j++])i++;
//			if (len_t - j < len_s - i) {
//				break;
//			}
//			if (i ==len_s || j ==len_t )break;
//		}
//		if (len_s-i<=len_t-j)printf("Yes\n");
//		else printf("No\n");
//	}
//	system("pause");
//	return 0;
//}