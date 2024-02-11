#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
	BOJ 1431 시리얼 번호
	https://www.acmicpc.net/problem/1431
*/
int n;
string arr[51];

bool comp(const string &a, const string &b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length()) {
		int aCnt = 0, bCnt = 0;
		for (auto aa : a) {
			if (aa >= '0' && aa <= '9') aCnt += (aa - '0');
		}
		for (auto bb : b) {
			if (bb >= '0' && bb <= '9') bCnt += (bb - '0');
		}
		if (aCnt == bCnt) return a < b;
		else return aCnt < bCnt;
		/*if (aCnt < bCnt) return true;
		else return a < b;*/
	}
	else
		return false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n, comp);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

}
