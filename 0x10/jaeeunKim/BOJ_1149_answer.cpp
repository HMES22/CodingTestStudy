#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 1149 실버1 RGB거리
	https://www.acmicpc.net/problem/1149

	DP 풀이... 점점 감을 잡아가는 중...
	1. 테이블 정의하기
		d[i][0] = i번째 집까지 칠할 때 비용의 최소값, 단 i번째 집은 R
		d[i][1] = i번째 집까지 칠할 때 비용의 최소값, 단 i번째 집은 G
		d[i][2] = i번째 집까지 칠할 때 비용의 최소값, 단 i번째 집은 B
	2. 점화식 찾기
		d[i][0] = min(d[i-1][1], d[i-1][2]) + h[i][0]
		d[i][1] = min(d[i-1][0], d[i-1][2]) + h[i][1]
		d[i][2] = min(d[i-1][0], d[i-1][1]) + h[i][2]

	3. 초기값 설정하기
		d[0][0] = h[0][0], d[0][1] = h[0][1], d[0][2] = h[0][2];
*/
int n;
int d[1001][3];
int h[1001][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i][0] >> h[i][1] >> h[i][2]; // i번째 집의 R, G, B칠하는 비용
	}
	d[1][0] = h[1][0];
	d[1][1] = h[1][1];
	d[1][2] = h[1][2];
	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + h[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + h[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + h[i][2];
	}
	//cout << min(min(d[n][0], d[n][1]), d[n][2]);
	cout << *min_element(d[n], d[n] + 3);
}