#include <iostream>
#include <queue>
using namespace std;
/*
	BOJ 12852 실버1 1로 만들기 2
	https://www.acmicpc.net/problem/12852

	BFS 풀이
    DP 풀이도 있음
*/
int n;
int dx[] = { 3, 2, 1 };
int dist[1'000'001];
int pre[1'000'001];
int main() {
	queue<int> q;
	cin >> n;
	q.push(1);
	dist[1] = 1;
	pre[1] = 0;
	while (!q.empty()) {
		auto num = q.front(); q.pop();
		int cnt = dist[num];
		if (num == n) {
			break;
		}
		for (int dir = 0; dir < 3; dir++) {
			int tmp;
			if (dir == 2) {
				tmp = num + dx[dir];
			}
			else {
				tmp = num * dx[dir];
			}
			if (tmp > 1'000'000) continue;
			if (dist[tmp] != 0) continue;
			q.push(tmp);
			dist[tmp] = cnt + 1;
			pre[tmp] = num;
		}
	}
	cout << dist[n] - 1 << '\n';
	cout << n << ' ';
	while (pre[n]) {
		cout << pre[n] << ' ';
		n = pre[n];
	}
}