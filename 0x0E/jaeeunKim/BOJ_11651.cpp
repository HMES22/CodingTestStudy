#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
    BOJ 11651 좌표 정렬하기 2
    https://www.acmicpc.net/problem/11651
*/
int n;
vector<pair<int,int>> v;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second)
		return (a.first < b.first);
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), comp);
	for (auto a : v)
		cout << a.first << ' ' << a.second << '\n';
}