#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    BOJ 15688 수 정렬하기 5
    https://www.acmicpc.net/problem/15688
*/
int n;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (auto a : v)
		cout << a << '\n';
}