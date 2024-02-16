/*
����
�⺻���� BFS���� �� ������ �ݺ��ϴ� �ݺ�ó�� �۾�


Ʋ���ų� �Ǽ��ߴ���

1. ��ũ�� ���ÿ� �� ; ����
2. �迭�ʱ�ȭ ���� (BFS�� ������ �����⶧���� �ʼ�)
3. ������ ������ Q.push ��������

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
				//������ �����
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

