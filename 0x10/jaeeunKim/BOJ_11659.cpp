#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 11659 실버3 "구간 합 구하기 4"
	https://www.acmicpc.net/problem/11659

	DP 풀이
	1. 테이블 정의하기
		d[n] = n번째 수까지 더한 합
	2. 점화식 찾기
		d[n] = d[n-1] + arr[n]
	3. 초기값 설정하기
		d[0] = 0
		
*/
int n, m;
int arr[100001];
int d[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	d[0] = 0;
	for (int i = 1; i <= n; i++) d[i] = d[i - 1] + arr[i];
	while (m--) {
		int st, en;
		cin >> st >> en;
		cout << d[en] - d[st - 1] << '\n';
	}
}