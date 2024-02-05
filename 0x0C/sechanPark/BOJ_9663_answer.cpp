/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/9663

* 번호(파일이름) :  BOJ_9663_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N-Queen / 골드 4 / 

* 설명 : 
	- NxN 보드에서 퀸을 서로 공격 할 수 없게 놓는 경우의 수를 구하라
	-
* 풀이 :
	1) 백트랙킹이다. 
	2) 재귀를 사용한다. 
* 기타 :
	- 기초문제라서 보고 풀었음~
	- 사실 상 'N과 M(1)'이랑 같은 문제라고 봐도 될듯, 구조는 완전 똑같음  
*/

#include <iostream>
using namespace std; 

bool vis_right[29]; 
bool vis_left[29]; 
bool vis_cur[15]; 

int n; 
int res = 0; 

void func(int cnt) {
	
	if (cnt == n) {
		res++; 
		return; 
	}

	for (int i = 0; i < n; i++) {
		if (vis_cur[i] || vis_right[i + cnt] || vis_left[cnt-i +n-1]) {
			continue; 
		}

		vis_cur[i] = 1;
		vis_right[i + cnt] = 1;
		vis_left[cnt - i + n - 1] = 1;
		func(cnt + 1); 
		vis_cur[i] = 0;
		vis_right[i + cnt] = 0;
		vis_left[cnt - i + n - 1] = 0;
	}
}
int main() {
	cin >> n; 
	func(0); 
	cout << res; 
}