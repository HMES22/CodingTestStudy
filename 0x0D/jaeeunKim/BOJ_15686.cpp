#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second
/*
	BOJ 15686 치킨 배달
	https://www.acmicpc.net/problem/15686

*/
int ans[14][101]; // 치킨집 x 집
int n, m;
int arr[51][51];
vector<pair<int, int>> h;
vector<pair<int, int>> c;
int tmp[14];
int result = 40000;
bool comp(pair<int, int> a, pair<int, int> b) {
	return a.Y <= b.Y;
}

int chickenNumber() {
	int res = 0;
	for (int dh = 0; dh < h.size(); dh++) {
		int min_ = 300;
		for (int i = 0; i < m; i++) {
			min_ = min(min_, ans[tmp[i]][dh]);
		}
		res += min_;
	}
	return res;
}
void func(int sx, int k) { 
	if (k == m) {// m개의 치킨 선택
		result = min(result, chickenNumber()); // 선택 완료시 도시치킨거리 구해서 최소값 갱신
		return;
	}
	for (int i = sx; i < c.size(); i++) {
		tmp[k] = i;
		func(i + 1, k + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) h.push_back({ i, j });
			if (arr[i][j] == 2) c.push_back({ i, j });
		}
	}

	for (int i = 0; i < c.size(); i++) { // distance 배열 채우기
		for (int j = 0; j < h.size(); j++) {
			ans[i][j] = abs(c[i].X - h[j].X) + abs(c[i].Y - h[j].Y);
		}
	}
	func(0, 0);
	cout << result;
	return 0;
}