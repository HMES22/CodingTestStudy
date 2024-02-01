/*
[24/02/01] sechanPark / 2문제
* 출처 : https://www.acmicpc.net/problem/17478

* 번호(파일이름) :  BOJ_1780.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 종이의 개수 / 실버 2 / 60분

* 설명 : 
	- 3의 배수로 NxN 행렬이 주어진다. 
	- 종이가 전부 같은 숫자로 채워지면 상관없는데
	- 다른 숫자로 채워지면, 정확히 9등분 해서 3의 배수 종이로 쪼갠다
	- 1x1이 될때 까지 이런식으로 종이를 계속 쪼갠다. 
	- 종이에 채워진 문자 별로 구분해서, 종이 개수를 출력한다.
* 풀이 :
	1) 재귀 함수는 한변의 길이와 탐색 시작 pos를 포함한다. 
	2) 시작 pos 부터 한변의 길이만큼 범위를 전부 탐색한다.
	3) 탐색 과정에서 이전 값과 같은 경우 flag를 올리고 반복문을 탈출한다.
	4) flag가 있는 경우 9개로 재귀한다. 
	5) 만일 한변의 길이가 없는 경우 종료조건으로 삼는다 
	6) flag가 없는 경우는 결과를 저장하고 종료한다
* 기타 :
	- 어렵진 않았는데, 전체 입력값을 저장하는게 배열이 너무 클까봐 고민을 많이해서 시간이 지체 되었따.. 
	- 생각보다 이정도 배열은 문제 없나보다.. 
	- 한 19MB? 정도되는듯? 
	- 그리고 분할 정복 해야하나 고민도 했는데, 이게 불가능 한거 같음
	- 경우가 있다면 알려좀 주쇼.. 
*/

#include <iostream>
using namespace std; 

int board[2200][2200]; 

int res[3]; 

void func(int n, int x, int y) {
	int flag = 0; 
	int bef = board[x][y]; 
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			int now; 
			now = board[i][j];
			
			
			if (now != bef) {
				flag = 1; 
				break; 
			}

			bef = now; 
		}
		
	}

	if (flag == 0) {
		res[bef+1] += 1; 
	}
	else if (flag == 1) {
		int side = n / 3;  
		if (side == 0) {
			return; 
		}
		func(side, x , y);
		func(side, x , y+side);
		func(side, x, y + side*2);

		func(side, x+side, y);
		func(side, x+side, y + side);
		func(side, x+side, y + side * 2);

		func(side, x + side*2, y);
		func(side, x + side*2, y + side);
		func(side, x + side*2, y + side * 2);
	}
}


int main() {
	int cnt;
	cin >> cnt; 

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			int x; 
			cin >> x; 
			board[i][j] = x; 
		}
	}

	func(cnt, 0, 0); 

	for (int i = 0; i < 3; i++) {
		cout << res[i] << "\n"; 
	}
	
}