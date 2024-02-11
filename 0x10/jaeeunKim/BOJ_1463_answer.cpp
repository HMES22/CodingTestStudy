#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 1463 실버3 1로 만들기
	https://www.acmicpc.net/problem/1463

	DP 풀이
	1. 테이블 정의하기
		D[i] = i를 1로 만들기 위해 필요한 연산 사용 횟수의 최소값
	2. 점화식 찾기
		D[k]
			if(k%3 == 0) D[k] = D[k/3] +1
			if(k%2 == 0) D[k] = D[k/2] +1
			D[k] = D[k-1] + 1
			이 중 최소값
	3. 초기값 설정하기
		D[1] = 0
*/
int n;
int D[1'000'001];
/*
void func(int k) {
	int tmp = D[k - 1] + 1;
	if (k % 3 == 0)
		tmp = min(tmp, D[k / 3] + 1);
	if (k % 2 == 0)
		tmp = min(tmp, D[k / 2] + 1);
	D[k] = tmp;
}
*/
int main() {
	cin >> n;
	D[1] = 0;
	for (int i = 2; i <= n; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
	}
	cout << D[n];
}