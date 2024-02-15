/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15666

* 번호(파일이름) :  BOJ_15666.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (12) / 실버 2 / 5분

* 설명 :
	-  

* 풀이 :
	1) 앞에 꺼 짬뽕임
* 기타 :
	- 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
vector <int> v1; 
vector <int> arr; 
vector <int> v2; 

void func(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return; 
	}

	for (int i = 0; i < n; i++) {
		if (depth > 0) {
			if (arr[depth-1] > v2[i])continue; 
		}

		arr[depth] = v2[i];
		func(depth + 1);
	}
}

int main(void) {
    cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v1.push_back(x); 
	}
	sort(v1.begin(), v1.end()); 

	int buf = 0; 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (buf == v1[i]) { 
			cnt++;
			buf = v1[i];
			continue; 
		}
		v2.push_back(v1[i]);
		buf = v1[i]; 
	}

	n -= cnt; 
	arr.assign(m, 0); 

	func(0); 
}