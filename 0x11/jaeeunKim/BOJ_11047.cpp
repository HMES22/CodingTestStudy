#include <iostream>
using namespace std;
/*
	BOJ 11047 실버4 동전 0
	https://www.acmicpc.net/problem/11047

*/

int n, k, ans;
int arr[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {
		ans += (k / arr[i]);
		k %= arr[i];
	}
	cout << ans;
	return 0;
}