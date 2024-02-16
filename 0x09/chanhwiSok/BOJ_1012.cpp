/*
문제
기본적인 BFS문제 에 여러번 반복하는 반복처리 작업


틀리거나 실수했던점

1. 매크로 사용시에 또 ; 붙임
2. 배열초기화 안함 (BFS를 여러번 돌리기때문에 필수)
3. 시작점 지정시 Q.push 잊지말기

*/

#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t;
int m, n, k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;

	for (int trying = 0; trying < t; trying++) {
		cin >> m >> n >> k;
		int board[54][54] = {};

		int vis[54][54] = {};

		int num = 0;


		for (int dot = 0; dot < k; dot++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;

		}
			
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//시작점 만들기
				queue<pair<int, int>>Q;
				if (vis[i][j] == 1 || board[i][j] == 0) continue;
				num++;
				Q.push({ i,j });

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis[nx][ny] == 1)continue;

						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
	cout << num << "\n";
			
	}
	
	
}

