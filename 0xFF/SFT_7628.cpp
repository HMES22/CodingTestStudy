#include <iostream>
using namespace std;
/*
	SFT 7628 연탄의 크기
	https://softeer.ai/practice/7628
*/
int r, n;
int nanro[101]; // 난로 배열

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nanro[i];
	}
	int max_ = 0;
	for (int i = 2; i <= 100; i++) { // 모든 연탄(단 1보다 커야 함)
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (nanro[j] % i == 0) // 난로가 연탄의 배수라면?
				cnt++;
		}
		max_ = max(max_, cnt);
	}
	cout << max_;
}