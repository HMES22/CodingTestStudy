/*
[24/02/02] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/2448

* 번호(파일이름) :  BOJ_2448.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 별 찍기 - 11 / 골드 4 / 20분 

* 설명 :
	- =='종이의 개수'
* 풀이 :
	1)
* 기타 :
	-
*/

//변의 길이가 n 이면 밑변은 2n -1 
//변의 길이가 3이 될때까지 재귀 

#include <iostream>
using namespace std; 

char board[3100][6201]; 

void func(int n, int x, int y) {
	if (n == 3) {

		board[x][y] = '*';

		board[x+1][y-1] = '*';
		board[x + 1][y + 1] = '*';

		board[x + 2][y - 2] = '*';
		board[x + 2][y - 1] = '*';
		board[x + 2][y - 0] = '*';
		board[x + 2][y + 1] = '*';
		board[x + 2][y + 2] = '*';
		return;
	}

	if (n > 3) {
		int side = n / 2; 

		func(side, x, y);
		func(side, x + side, y - side);
		func(side, x + side, y + side);
	}
}

int main() {
	for (int i = 0; i < 3100; i++) {
		for (int j = 0; j < 6201; j++) {
			board[i][j] = ' '; 
		}
	}

	int cnt; 
	cin >> cnt; 
	
	func(cnt, 0, cnt-1); 

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt * 2 + 1; j++) {
			cout << board[i][j]; 
		}
		cout << "\n"; 
	}
}