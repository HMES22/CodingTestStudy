#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 11726 실버3 2xn 타일링
	https://www.acmicpc.net/problem/11726

	DP 풀이
	1. 테이블 정의하기
		d[n] = 2xn 크기의 직사각형을 채우는 방법의 수
	2. 점화식 찾기
		d[k] = d[k-1] + d[k-2]
        2xn을 채우는 경우의 수는 첫번째 타일을 (2x1)로 하는 경우와 (1x2)x2로 하는 경우 2가지로 나눌 수 있음
            첫번째 타일을 (2x1)로 하는 경우는 나머지 k-1를 채우는 경우와 같음 d[k-1]
            첫번째 타일을 (1x2) 2개로 하는 경우 나머지 k-2를 채우는 경우와 같음 d[k-2]

	3. 초기값 설정하기
		d[1] = 1, d[2] = 2
*/
int n;
int d[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	d[1] = 1, d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n] % 10007;
}