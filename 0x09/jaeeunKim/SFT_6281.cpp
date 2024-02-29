#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
	SFT 6281 Lv.3 "동계 테스트 시점 예측"
	https://softeer.ai/practice/6281
	Time: 2024-02-21) 21:21~23:13.. 인데 중간에 딴짓함 ㅎ

    
	test case 2
	8 9
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 1 1 0 0 0 1 1 0
	0 1 0 1 1 1 0 1 0
	0 1 0 0 1 0 0 1 0
	0 1 0 1 1 1 0 1 0
	0 1 1 0 0 0 1 1 0
	0 0 0 0 0 0 0 0 0
	3
*/

#define X first
#define Y second
int n, m; // n x m 임
int ans = 0;
int arr[101][101];
bool dsp[101][101];
bool real[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

bool allZero() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (arr[i][j]) return false;
	}
	return true;
}

void check() {
	// 1로 둘러쌓인 0의 i,j 위치를 yet[i][j] = true로 체크해버리자
	for (int i = 0; i < n; i++)
		fill(real[i], real[i] + m, false);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	real[0][0] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (arr[nx][ny] != 0) continue;
			if (real[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			q.push({ nx,ny });
			real[nx][ny] = true;
		}
	}

}
void melting() { // 2변 이상이 공기와 접촉한 원소 Check;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 1) continue;
			int tmp = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (arr[nx][ny] == 0 && real[nx][ny]) tmp++;
			}
			if (tmp >= 2) dsp[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (dsp[i][j]) arr[i][j] = 0;
	ans++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (!allZero()) {
		check();
		melting();
	}
	cout << ans;
}