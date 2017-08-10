#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

typedef struct {
	char f_str[51];
	int index;
}Str_index;

Str_index* getNewStr_index() {
	Str_index* res = (Str_index*)malloc(sizeof(Str_index));
	strcpy(res->f_str, "");
	res->index = -1;
	return res;
}
//int main() {
//	int n = 0;
//	cin >> n;
//	cin.ignore();
//
//	int index_max = 0;
//	vector<Str_index> group_str_index;
//
//	for (int i = 0; i < n; ++i) {
//		char f[51];
//		cin.getline(f, 51);
//
//		string s_f = f;
//		int index = s_f.find('.');
//
//		//实例化结构体并赋值
//		Str_index* str_index = getNewStr_index();
//		strcpy(str_index->f_str, f);
//		str_index->index = index;
//
//		group_str_index.push_back(*str_index);
//
//		index_max = (index > index_max) ? index : index_max;
//	}
//	for (int i = 0; i < n; ++i) {
//		int dis = index_max - group_str_index[i].index;
//		for (int j = 0; j < dis; ++j)cout << " ";
//		cout << group_str_index[i].f_str << endl;
//	}
//	system("pause");
//	return 0;
//}