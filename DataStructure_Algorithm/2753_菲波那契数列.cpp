/*考前练习 动态规划*/
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//static int fb[21];
//int main() {
//	fb[1] = fb[2] = 1;
//	for (int i = 3; i <= 20; ++i)fb[i] = fb[i - 1] + fb[i - 2];
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int a;
//		scanf("%d", &a);
//		printf("%d\n", fb[a]);
//	}
//}
/*考前练习 递归法*/
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int fb(int a) {
//	if (a == 1 || a == 2)return 1;
//	return fb(a - 1) + fb(a - 2);
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//
//	while (n--)
//	{
//		int a;
//		scanf("%d", &a);
//		int res = fb(a);
//		printf("%d\n", res);
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//int fibonacci(int a) {
//	if (a == 2 || a == 1)return 1;
//	return fibonacci(a - 1) + fibonacci(a - 2);
//}
//int main() {
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		int a = 0;
//		cin >> a;
//		cout<<fibonacci(a)<<endl;
//	}
//	system("pause");
//	return 0;
//}