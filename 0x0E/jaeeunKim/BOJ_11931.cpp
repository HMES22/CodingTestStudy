#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    BOJ 11931 수 정렬하기 4
    https://www.acmicpc.net/problem/11931
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
	sort(v.begin(), v.end(), greater<int>());
	for (auto a : v)
		cout << a << '\n';
}