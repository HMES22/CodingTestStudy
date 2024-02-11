#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 12852 실버1 1로 만들기 2
	https://www.acmicpc.net/problem/12852

	DP 풀이
	1. 테이블 정의하기
		d[n] = n을 1로 만드는 최소 경우의 수
        pre[n] = n을 1로 만드는 이전 값(경로)
	2. 점화식 찾기
		d[k] 
            1. d[k-1] +1, pre[k] = k-1
            2. k%2 == 0) d[k/2]+1, pre[k] = k/2
            3. k%3 == 0) d[k/3]+1, pre[k] = k/3
            위 경우 d[k] 가 최소가 되는 경우 d[k], pre[k] 갱신
	3. 초기값 설정하기
		d[1] = 0, pre[1] = 0
		
*/

int n;
int d[1'000'001];
int pre[1'000'001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	d[1] = 0, pre[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0) {
			if (d[i] > (d[i / 2] + 1)) {
				d[i] = d[i / 2] + 1;
				pre[i] = i / 2;
			}
		}
		if (i % 3 == 0) {
			if (d[i] > (d[i / 3] + 1)) {
				d[i] = d[i / 3] + 1;
				pre[i] = i / 3;
			}
		}
	}
	cout << d[n] << '\n';
	cout << n << ' ';
	while (pre[n] != 0) {
		cout << pre[n] << ' ';
		n = pre[n];
	}
}