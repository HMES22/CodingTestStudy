#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 2146 다리 만들기
	https://www.acmicpc.net/problem/2146

	대륙 간 구별하는 BFS를 위한 큐(q1)
	대륙 간의 다리 길이를 구하는 BFS를 위한 큐(q2)
	거리를 구하기 위한 배열(dist)

	1. 대륙을 BFS로 탐색하여 같은 대륙에 속한 arr값은 동일하게 설정한다.
		1-1. 좌표를 q1에 push할 때, 상하좌우 값이 하나라도 0인 경우 q2에 대입
		1-2. q1에 있는 좌표는 pop하지만, q2는 pop하지 않는다.(다리를 구하기 위해)
	2. 구역 하나를 검색하는 BFS 종료시, q2가 empty일 때 까지 BFS
		2-1. 상하좌우 검색시 arr원소가 0이면서 방문하지 않은 경우만 push
		2-2. arr원소가 0이 아닌 경우 탐색 종료
		2-3. 거리값 갱신
*/
#define X first
#define Y second
int n;
int arr[101][101];
int dist[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int area = 1;

void print() {
	cout << "--------------------arr------------------------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << "--------------------dist------------------------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << dist[i][j] << ' ';
		cout << '\n';
	}
}

int bfs(int i, int j) { //(i,j) 에서 다른 대륙으로 가는 다리의 최소값을 리턴하는 함수
	area++;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	for (int t = 0; t < n; t++)
		fill(dist[t], dist[t] + n, 0);
	q.push({ i,j });
	arr[i][j] = area;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.X;
			int ny = dy[dir] + cur.Y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == 0) {
				q2.push({ cur.X, cur.Y }); // 주변이 바다인 대륙은 q2에 저장(다른 대륙간의 거리를 구하는 BFS의 시작점들임)
				dist[cur.X][cur.Y] = 1; // 시작점의 거리값은 1로 초기화!
				continue;
			}
			if (arr[nx][ny] != 1) continue;
			q.push({ nx, ny });
			arr[nx][ny] = arr[cur.X][cur.Y];
		}
	}
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.X;
			int ny = dy[dir] + cur.Y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == area) continue; // 같은 대륙에 도착한 경우
			if (dist[nx][ny] != 0) continue; // 이미 방문한 경우
			if (arr[nx][ny] != area && arr[nx][ny] != 0) { // 다른 대륙에 도착한 경우
				return dist[cur.X][cur.Y] - 1;
			}
			q2.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int min_ = 10001;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				min_ = min(min_, bfs(i, j)); // 대륙별 다리 길이의 최소값 갱신!
			}

		}
	}
	cout << min_ << '\n';

}