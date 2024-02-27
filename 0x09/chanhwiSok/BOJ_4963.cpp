/*
대각선 활용하는 첫dfs 문제

dx dy만 바꿔주면 ok


*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[51][51];
int vis[51][51];
int dx[8] = {1, 1, 0,-1,-1,-1,0,1};
int dy[8] = {0, 1, 1,1,0,-1,-1,-1};
int n,m;
int land=0;

int main() {
	freopen("input.txt", "r", stdin);
	while (1) {
		land = 0;
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				vis[i][j] = 0;
			}
		}
		

		queue <pair<int, int>>Q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {
					land++;
					vis[i][j] = 1;
					Q.push({ i,j });



					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 8; dir++) {
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

		}
		cout << land << "\n";

	}
}