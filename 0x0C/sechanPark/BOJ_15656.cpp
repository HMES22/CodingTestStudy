/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15656

* 번호(파일이름) :  BOJ_15656.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (7) / 실버 3 / 10분

* 설명 :
	-  

* 풀이 :
	1) 풀이 생략 
* 기타 :
	- STL은 신이야 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
vector <int> v1; 
vector <int> arr;

void func(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " "; 
		}
		cout << "\n"; 
		return; 
	}

	for (int i = 0; i < n; i++) {
		arr[depth] = v1[i];
		func(depth + 1); 
	}
}


int main(void) {
    cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v1.push_back(x); 
	}
	arr.assign(n, 0); 
	sort(v1.begin(), v1.end()); 

	func(0); 
}