/*
BFS �����ϴ� �ð� �������� Ǯ��� ������ ����


���� �ٽ� : 
1. int -> string �� to_string ���
2. ���ڿ��� ����������? str[i] - '0'
(int �� ���� ������ �ƽ�Ű �ڵ峪�͹���)


*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	vector<int>n(10);
	int a, b, c;
	int res;
	cin >> a >> b >> c;

	res = a * b * c;
	string str = to_string(res);
	
	
	/*for (int i = 0; i < str.size(); i++) {
		for(int j=0; j<10; j++){
			if (int(str[i]) == j) n[j]++;
		}
	}*/    // ==> int(str[i])�� �ƽ�Ű �ڵ� ��ȯ��

	for (int i = 0; i < str.size(); i++) {
		n[str[i] - '0']++;
	}
	// ���ڿ��� ������ ��ȯ�ϴ� �ùٸ� ��� : str[i] - '0'


	for (int i = 0; i < 10; i++) {
		cout << n[i] << "\n";
	}
}