#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 2579 실버3 계단 오르기
	https://www.acmicpc.net/problem/2579

	DP 풀이
	1. 테이블 정의하기
		d[i][j] = 현재까지 j개의(이전계단 +i번째) 계단을 연속해서 밟아서 i번째 계단까지 올라섰을 때 점수 합의 최대값
				, 단 i번째 계단은 반드시 밟아야 함
		
	2. 점화식 찾기
		d[k][2] = 연속으로 2번 밟아서 k번째 올랐을 때니까, 이전에는 무조건 k-1을 밟았을 것.
				= d[k-1][1] + s[k] 
		d[k][1] = 연속으로 1번 밟아서(즉 k가 첫번째 계단), 그렇다면 k-1은 밟지 않았다는 뜻
				= max(d[k-2][1], d[k-2][2]) + s[k]

	3. 초기값 설정하기
		d[1][1] = s[1], d[2][1] = s[2]
		d[1][2] = 0   , d[2][2] = s[1] + s[2]
*/
int n;
int s[301];
int d[301][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	d[1][1] = s[1], d[1][2] = 0;
	d[2][1] = s[2], d[2][2] = s[1] + s[2];
	for (int i = 3; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
		d[i][2] = d[i - 1][1] + s[i];
	}
	cout << max(d[n][1], d[n][2]);
}