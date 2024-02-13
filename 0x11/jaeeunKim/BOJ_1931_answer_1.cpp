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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> met[i].second >> met[i].first;
	sort(met, met + n); 
	int st = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if(st <= met[i].second){
			ans++;
			st = met[i].first;
		}
	}
	cout << ans;
	return 0;
}