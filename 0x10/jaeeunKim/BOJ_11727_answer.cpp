#include <iostream>
using namespace std;
/*
    BOJ 11727 실버3 "2xn 타일링 2"
    https://www.acmicpc.net/problem/11727
	1. 테이블 정의
		d[n] = 2xn 크기를 채우는 방법의 수
	2. 점화식
		d[k]
			d[k-1] + 2*d[k-2]
	3. 초기화
		d[1] = 1 d[2] = 3
*/
int n;
int d[1001];
int main() {
	cin >> n;
	d[1] = 1; d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2])  % 10007;
	}
	cout << d[n] % 10007;

}