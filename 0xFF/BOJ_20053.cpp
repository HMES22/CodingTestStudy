#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
    BOJ 20053 최소, 최대 2
    https://www.acmicpc.net/problem/20053
*/
int t, n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int min_ = INT_MAX;
		int max_ = INT_MIN;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			min_ = min(tmp, min_);
			max_ = max(tmp, max_);
		}
		cout << min_ << ' ' << max_ << '\n';
	}
}