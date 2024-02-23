//초기 시작점 잡는거 감안와서 못품

/* 발상순서

<필요한 함수>
1. 모든 것이 같은 색으로 칠해졌는지 확인하는 함수
2. 색을 확인하고, 필요한 경우 4등분하여 재귀하는 함수.

<1번 함수>
순회 하고 다른색 있으면 false 반환. false는 곧 재귀 조건.
true 라면 갯수세고 종료.

<2번 함수>
1번함수를 호출하고 검사.
다른경우 '자르고', 재귀 호출

<main>
초반 점 설정에 대해 func

*/


#include<bits/stdc++.h>
using namespace std;
int n;

int board[130][130];
int ans[2];

bool check(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++)
			//1. 현재값과 초기값을 비교
			//다르다면 false => 다시 재귀
		{
			if (board[i][j] != board[x][y]) return false;
		}
	
	}
	return true;
}

void func(int n, int x, int y) {
	if (check(n, x, y)) {		
		ans[board[x][y]]++; 
		return; //check 함수 에서 true이면 종이 갯수만 추가후 종료
				//동시에 기저 역활
	}
	//false이면 자르고 다시 갯수 세기
	for (int i = 0; i < 2; i++) //네영역으로 나누기(자르기)
		for (int j = 0; j < 2; j++) 
			func(n / 2, x + i * n / 2, y + j * n / 2);
			//시작점 4개가 생기고, 각 함수 동작.
}


int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	func(n, 0, 0); //첫 시작. 

	for (int i = 0; i < 2; i++) cout << ans[i] << '\n';

}

