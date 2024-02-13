#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 1931 실버1 회의실 배정
	https://www.acmicpc.net/problem/1931
	
	회의시간이 짧은 순, 그리고 시작 시간이 빠른 순으로 회의를 배치 => X
	현재 시간 t에서 실행가능한 회의중 가장 빨리 끝나는 회의들로 배치 => O

*/

int n;
pair<int, int> met[100'001];

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) return a.first < b.first; // 끝나는 시간이 같다면 시작 시간이 빠른 순으로! (1,2)와 (2,2) 가 있다면 (1,2) 부터 실행한 후 (2,2) 가 실행되어야 함
	else return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> met[i].first >> met[i].second;
	sort(met, met + n, comp); // second 값을 기준으로 정렬(가장 빨리 끝나는 회의 순으로)
	int st = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (st <= met[i].first) {
			//cout << met[i].first << ' ' << met[i].second << '\n';
			ans++;
			st = met[i].second;
		}
	}
	cout << ans;
	return 0;
}