/*
이차원 배열 + 이차원 배열 문제만 보다가 당황

단순 숫자들의 관계를 묻는 문제라면 일차원 배열로 확인 가능함.

*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101];
int vis[101];

int main() {
	int n, m;
	int x, y;
	int cnt;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		board[x][y] = board[y][x] = 1;
	}

	queue<int>Q;
	Q.push(1);
	vis[1]=1;

	while (!Q.empty()) {
		int current = Q.front(); Q.pop();

		for (int i = 1; i <= n; i++) {
			if (board[current][i] == 1 && vis[i] == 0);
			{
				vis[i] = 1;
				Q.push(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}