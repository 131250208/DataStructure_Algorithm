/*Accepted
排序就好了
*/
#include<iostream>
#include<iomanip>
using namespace std;
static int w, s;//包可承重上限，金属种类数
typedef struct{
	int weight;
	double price_total, price;
}Metal;
Metal metals[100];
Metal* getInstance_metal(int weight,double price_t) {
	Metal* metal = (Metal*)malloc(sizeof(Metal));
	metal->weight = weight;
	metal->price_total = price_t;
	metal->price = price_t / weight;
	return metal;
}

int cmp_metal(const void* m1, const void* m2) {
	Metal* metal1 = (Metal*)m1;
	Metal* metal2 = (Metal*)m2;
	return metal1->price > metal2->price?-1:1;
}
void del_group_2795() {
	cin >> w; 
	cin >> s;
	int weight; double price_t;
	for (int i = 0; i < s; ++i) {
		cin >> weight; cin >> price_t;
		metals[i] = *getInstance_metal(weight, price_t);
	}
	//给金属按单价排降序
	qsort(metals, s, sizeof(metals[0]), cmp_metal);
	//装包
	double price_inbag = 0;
	for (int i = 0; i < s; ++i) {
		if (metals[i].weight < w) {
			w -= metals[i].weight;
			price_inbag += metals[i].price_total;
		}
		else
		{
			price_inbag += w*metals[i].price;
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << price_inbag << endl;
}
//int main() {
//	int group;
//	cin >> group;
//	for (int i = 0; i < group; ++i) {
//		del_group_2795();
//	}
//	system("pause");
//	return 0;
//}