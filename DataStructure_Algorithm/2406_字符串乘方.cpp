//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//
//static char str[1000010];
//static int fail[1000010];
//int main() {
//
//	while (true)
//	{
//		scanf("%s", &str);
//		if (strcmp(str, ".") == 0)break;
//
//		int len = strlen(str);
//		if (len == 1) {
//			printf("1\n");
//			continue;
//		}
//		//求next向量组
//		int i = 1, j = 0; fail[0] = 0;
//
//		for (int i=1;i<len;) {
//			if (str[i] == str[j]) {
//				fail[i] = j + 1;
//				j++;
//				i++;
//			}
//			else
//			{
//				if(j!=0)j = fail[j - 1];
//				else fail[i++] = 0;
//			}
//		}
//		//计算循环节长度
//		if (len % (len - fail[len - 1]) != 0)printf("1\n");
//		else printf("%d\n", len / (len - fail[len - 1]));
//	}
//	system("pause");
//	return 0;
//}