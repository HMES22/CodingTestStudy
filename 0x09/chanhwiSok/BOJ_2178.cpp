/*
BFS를 활용한 거리 문제 (기본)

1. 문자들이 붙어서 나오는거 배열로 처리할때 string 활용하기!

2. 거리를 위한 배열에는 -1 채우기 ( 거리 0이 있으므로!!)


*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int n, m;
queue<pair<int, int>>Q;
string board[102];   
int dist[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



int main() {

	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<pair<int, int>> Q;
	
	Q.push({ 0,0 });
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	dist[0][0] = 0;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if ( dist[nx][ny] >= 0 || board[nx][ny] != '1' ) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			
			Q.push({nx,ny});
		}
	}

	cout << dist[n-1][m-1]+1;

}