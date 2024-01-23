#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 9663 N-Queen
	https://www.acmicpc.net/problem/9663

	현재 N-Queens 가 가능한 좌표의 수열을 구하고 있음
	ex ( 0,2) (1,0) (2,3) (3,2) 라고 했을 때 이 4가지 좌표의 배열 순서에 따른 경우의 수를 다 체크함
	아까 N과 M 문제와 똑같이 구현했기 때문에 그럼

	다시 구현 필요
	0행의 0부터 N-1까지의 열에 대해서 한번만 순회해보기!
*/
#define X first
#define Y second
int n;

int ans;
vector<pair<int, int>> v;
bool isused[15][15];
bool check(int x, int y) {
	for (auto q : v) {
		if (q.X == x || q.Y == y || (q.X + q.Y) == (x + y) || (q.X - q.Y) == (x - y))
			return false;
	}
	return true;
}
void func(int k) { // k번째 row에 말을 배치할 거임
	if (k == n) {
		++ans;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check(k, i)) {
			v.push_back({ k,i });
			func(k + 1);
			v.pop_back();
		}
	}
}
int main() {
	cin >> n;
	func(0);
	cout << ans;
}