#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 9095 실버3 1,2,3 더하기
    https://www.acmicpc.net/problem/9095

	DP 풀이
	1. 테이블 정의하기
		d[i] = i를 1,2,3 의 합으로 나타내는 방법의 수
	2. 점화식 찾기
		d[k] = d[k-1] + d[k-2] + d[k-4]
	3. 초기값 설정하기
		d[1] = 1, d[2] = 2, d[3] = 4
*/
int n,test ;
int d[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> test;
    d[1] = 1, d[2] = 2, d[3] = 4;
    
    for (int i = 4; i <= 11; i++) {
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    }
	while (test--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}