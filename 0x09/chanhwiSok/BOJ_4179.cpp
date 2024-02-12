/*
BFS�� �ι� ���� ������ ���ϴ� ����
*/


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
string board[1002];
int vis1[1002][1002]; //�����Ľð�
int vis2[1002][1002]; // ������ �̵��ð�
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



int main() {
	queue<pair<int, int>>Q1; //��
	queue<pair<int, int>>Q2; // ������
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fill(vis1[i], vis1[i] + m, -1);
		fill(vis2[i], vis2[i] + m, -1);
	}

	for (int i = 0; i < n; i++) cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				vis1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				vis2[i][j] = 0;
			}
		}
	}

	while (!Q1.empty()) {
		auto cur = Q1.front(); Q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis1[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;

			Q1.push({ nx,ny });
		}
	}

	while (!Q2.empty()) {
		pair<int, int>cur = Q2.front(); Q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // Ż���� ������ ��� �ð�(��)�� ���
				cout << vis2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (vis2[nx][ny] >= 0 || board[nx][ny] == '#') continue; //���� �̵����� ���ϰ���.
			if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1) continue;
			vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";


	
}