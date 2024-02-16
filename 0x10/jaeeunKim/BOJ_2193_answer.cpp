#include <iostream>
using namespace std;
/*
	BOJ 2193 실버3 "이친수"

	1. d[n] = n자리 이친수의 개수
	2. d[k] = d[k-1] + d[k-2]
	3. d[1] = 1, d[2] = 1
*/
int n;
long long d[91]; // int시 틀림 ㅅㅂ
int main() {
	cin >> n;
	d[1] = 1, d[2] = 1;
	for (int i = 3; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];
	cout << d[n];
}