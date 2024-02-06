/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15652

* 번호(파일이름) :  BOJ_15652.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (4) / 실버 3 / 20분

* 설명 :
	-
* 풀이 :
	1)
* 기타 :
	-
*/

#include <iostream>
using namespace std;

int n, m; 
int arr[8]; 
int option[8]; 

void func(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n"; 
		return; 
	}

	for (int i = 1; i <= n; i++) {
		if (depth > 0) {
			if (arr[depth - 1] <= i) {
				arr[depth] = i;
				func(depth + 1);
			}
		}
		else {
			arr[depth] = i;
			func(depth + 1);
		}
	}
}
int main() {
	cin >> n >> m; 
	func(0); 
}