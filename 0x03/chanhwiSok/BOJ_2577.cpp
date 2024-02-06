/*
BFS 복습하다 시간 다지나서 풀어보는 자투리 문제


문제 핵심 : 
1. int -> string 은 to_string 사용
2. 문자열을 정수형으로? str[i] - '0'
(int 로 씌워 버리면 아스키 코드나와버림)


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
	}*/    // ==> int(str[i])는 아스키 코드 반환함

	for (int i = 0; i < str.size(); i++) {
		n[str[i] - '0']++;
	}
	// 문자열을 정수로 변환하는 올바른 방법 : str[i] - '0'


	for (int i = 0; i < 10; i++) {
		cout << n[i] << "\n";
	}
}