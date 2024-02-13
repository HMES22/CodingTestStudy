#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 2217 실버4 로프
	https://www.acmicpc.net/problem/2217
*/
int n, ans;
int arr[100'001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	for (int i = 1; i <= n; i++) {
		ans = max(ans, arr[i - 1] * i);
	}
	cout << ans;
}