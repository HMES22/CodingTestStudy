/*
시작점이 2개이상이라면??
=> 초기점 잡을때 Q에 여러개 넣으면 된다!!

행렬 입력값 m,n 거꾸로 되있는 문제도 있으니 주의하기!!
=> 이거때문에 한참 헤맴.

*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[1002][1002];
int vis[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int day;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> m >> n;

	queue<pair<int, int>> Q;


	//시작점 Q
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {  //출발지점
				Q.push({ i,j });
			}
			if (board[i][j] == 0) { //0이라면 일단 익지않은것
				vis[i][j] = -1;// '아직' 익지 않았으니 -1(시간)
			}
		}
	}

	


	while (!Q.empty()) {


		pair<int, int>cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] >= 0) continue; //토마토가 익은것

			vis[nx][ny] = vis[cur.X][cur.Y] + 1; //day를 셈
			Q.push({nx,ny});

		}
	}

	//vis 확인 및 출력 단계
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == -1) {
				cout << -1;
				return 0;
			}
			day = max(day, vis[i][j]); //vis중 최대값 = 날짜
		}
	}

	cout << day;
	
}