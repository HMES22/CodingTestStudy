#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 13549 숨바꼭질 3
	https://www.acmicpc.net/problem/13549

	2배로 순간이동 하는 경우는 0초이기 때문에 -1, +1 하는 경우보다 먼저 검사해야 함!
*/
int n, k;
int d[] = { 2, -1, 1 };
bool vis[100001];
int main() {
	queue<pair<int, int>> q;
	cin >> n >> k;
	vis[n] = true;
	q.push({ n,0 });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int num = cur.first;
		int sec = cur.second;
		if (num == k) {
			cout << sec << '\n';
			return 0;
		}
		for (int dir = 0; dir < 3; dir++) {
			int nxtNum;
			int nxtSec;
			if (dir == 0) {
				nxtNum = num * d[dir];
				nxtSec = sec;
			}
			else {
				nxtNum = num + d[dir];
				nxtSec = sec + 1;
			}
			if (nxtNum < 0 || nxtNum > 100000) continue;
			if (vis[nxtNum]) continue;
			q.push({ nxtNum, nxtSec });
			vis[nxtNum] = true;
		}
	}
	return 0;
}