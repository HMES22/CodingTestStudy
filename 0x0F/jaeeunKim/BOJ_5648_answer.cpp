#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
	BOJ 5648 실버5 "역원소 정렬"
	https://www.acmicpc.net/problem/5648

	string을 입력받아 reverse함수로 원소를 뒤집는 방법
*/
using ull = unsigned long long;
int n;
vector<ull> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stoull(s));
	}
	sort(v.begin(), v.end());
	for (auto x : v) cout << x << '\n';
}