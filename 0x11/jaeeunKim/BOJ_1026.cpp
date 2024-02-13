#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 1026 실버4 보물
	https://www.acmicpc.net/problem/1026
*/
int n;
int a[51], b[51];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n); 
	sort(b, b + n, greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i++) ans += a[i] * b[i];
	cout << ans;	
}