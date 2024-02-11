#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
    BOJ 10814 나이순 정렬
    https://www.acmicpc.net/problem/10814

    compare 함수에서 두 값이 같을 때는 false를 반환하도록 하기! 
    https://youtu.be/dq5t1woLJMw?si=KGWHyAYMJMdkrGP3&t=1034

*/
int n;
vector<pair<int,string>> v;
bool comp(const pair<int, string> &a, const pair<int, string> &b) {
	if (a.first < b.first) return true;
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

	stable_sort(v.begin(), v.end(), comp);
	for (auto a : v)
		cout << a.first << ' '<< a.second << '\n';
}