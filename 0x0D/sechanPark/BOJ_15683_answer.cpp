/*
[24/02/15] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/15683

* 번호(파일이름) :  BOJ_15683_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 감시 / 골드 4 / 120분

* 설명 :
	- 링크 참고 
* 풀이 :
	1) 상하좌우, 이동을 위한 dx dy 정의(bfs 하던거 마냥)
	2) 모든 경우를 다본다? 백트랙킹 할꺼임 
	3) 처음에 입력 받을 때 cctv 위치랑 cctv 종류량 받아서 vec에 저장
	4) 재귀함수에서 첫번째 깊이에 해당하는 cctv 빼서
	5) 해당하는 번호에 대해서 dfs수행함 
	6) 그리고 다음 cctv로 재귀함 
	7) 360도 돌꺼라서 for문 4번돌림
	8) 중요한건 보드값을 계속 재귀 할때마다 새롭게 쓰니깐 버퍼에 임시저장해놓고 
	9) 재귀 돌아오면 다시 롤백 해줘야함 / 해당 위치 상태를 유지하는 그런 느낌
	10) 이건 마치 백트랙킹 할때 비슷한거임 
* 기타 :
	- 뭐 그냥 찝찝하고 한거 같지도 않고 자괴감 듬 자살매렵네 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m; 
int board[8][8]; 

//상-우-하-좌 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; 

int res = 100; 

vector <tuple<int ,int, int>> v; 

void check(int x, int y, int dir) {
	dir = dir % 4; 
	int nx = x; 
	int ny = y; 
	while (1){
		nx += dx[dir]; 
		ny += dy[dir]; 

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)return; 
		if (board[nx][ny] == 6)return; 
		if (board[nx][ny] != 0)continue; 

		board[nx][ny] = -1; //-1 == '#'
	}
}

void dfs(int depth) {
	if (depth == v.size()) {
		int buf = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0)
					buf++;
			}
		}
		res = min(res, buf); 
		return; 
	}

	int buf[8][8]; 

	for (int i = 0; i < 4; i++) {
		//버퍼 채우기(재귀전에 원래 값) 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				buf[i][j] = board[i][j];
			}
		}

		int x, y, cctv; 
		tie(x, y, cctv) = v[depth]; 

		//cctv 검사 쭉 돌림 
		switch (cctv){
		case 1: 
			check(x,y,i); 
			break; 
		case 2:
			check(x, y, i);
			check(x, y, i+2);
			break;
		case 3:
			check(x, y, i);
			check(x, y, i+1);
			break;
		case 4:
			check(x, y, i);
			check(x, y, i+1);
			check(x, y, i+3);
			break;
		case 5:
			check(x, y, i);
			check(x, y, i+1);
			check(x, y, i+2);
			check(x, y, i+3);
			break;
		default:
			break;
		}

		//재귀 
		dfs(depth + 1); 

		//원래로 돌려놓기 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = buf[i][j];
			}
		}
	}
}

int main() {
	//입력 받기 
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; 
			cin >> x; 
			board[i][j] = x; 

			if (x > 0 && x < 6) {
				v.push_back({ i,j,x}); 
			}
		}
	}

	dfs(0); 

	cout << res; 
}