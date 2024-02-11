#include <iostream>
#include <queue>
using namespace std;
/*
    BOJ 1463 실버3 1로 만들기
    https://www.acmicpc.net/problem/1463

    BFS 풀이
*/
int n;
int dx[] = { 3, 2, 1 };
int dist[1'000'001];
int main() {
	queue<int> q;
	cin >> n;
	q.push(n);
	dist[n] = 1;
	while (!q.empty()) {
		auto num = q.front(); q.pop();
		int cnt = dist[num];
		if (num == 1) {
			cout << cnt-1 << '\n';
			return 0;
		}
		for (int dir = 0; dir < 3; dir++) {
			int tmp;
			if (dir == 2) {
				tmp = num - dx[dir];
			}
			else {
				if (num % dx[dir] == 0) {
					tmp = num / dx[dir];
				}
				else continue;
			}
			if (tmp <= 0) continue;
			if (dist[tmp] != 0) continue;
			q.push(tmp);
			dist[tmp] = cnt + 1;
		}
	}
}