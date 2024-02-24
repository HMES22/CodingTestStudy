//색종이 만들기 문제랑 거의 똑같음.

#include<bits/stdc++.h>
using namespace std;
int n;
int paper[2187][2187];
int ans[3];

bool check(int n, int x, int y){
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			if (paper[i][j] != paper[x][y])return false;
		}
	}
	return true;
}

void func(int n, int x, int y) {
	if (check(n, x, y)) {
		ans[paper[x][y] + 1]++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			func(n / 3, x + i * n / 3, y + j * n / 3);
		}
	}

}




int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	func(n, 0, 0);

	for (int i = 0; i < 3; i++)
		cout << ans[i] <<"\n";
}