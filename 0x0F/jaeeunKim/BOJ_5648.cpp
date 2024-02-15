#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    BOJ 5648 실버5 "역원소 정렬"
    https://www.acmicpc.net/problem/5648
*/
using ull = unsigned long long;
int n;
vector<ull> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		ull tmp;
		ull real = 0;
		cin >> tmp;
		while (tmp) {
			real = real * 10  + (tmp % 10);
			tmp /= 10;
		}
		v.push_back(real);
	}
	sort(v.begin(), v.end());
	for (auto x : v)
		cout << x << '\n';
}