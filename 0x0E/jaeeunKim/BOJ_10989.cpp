#include <iostream>
using namespace std;
/*
	BOJ 10989 수 정렬하기 3 
	https://www.acmicpc.net/problem/10989
*/
int n;
int cnt[10'001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int c = 0; c < cnt[i]; c++)
			cout << i << '\n';
	}
}