#include <iostream>
#include <string>
using namespace std;
/*
	BOJ 14891 골드5 "톱니바퀴"
	https://www.acmicpc.net/problem/14891
*/
int k;
string arr[4];
int r[4] = { 0 };

int result() {
	int res = 0;
	if (arr[0][0] == '1') res += 1;
	if (arr[1][0] == '1') res += 2;
	if (arr[2][0] == '1') res += 4;
	if (arr[3][0] == '1') res += 8;
	return res;
}

void startRot(int idx) {
	int cur = r[idx]; // 현재 idx의 방향값
	if (idx == 0) {
		for (int i = idx; i < 3; i++) {
			if (arr[i][2] != arr[i + 1][6]) r[i + 1] = r[i] * -1;
			else break;
		}
	}
	else if (idx == 1 || idx == 2) {
		for (int i = idx; i < 3; i++) {
			if (arr[i][2] != arr[i + 1][6]) r[i + 1] = r[i] * -1;
			else break;
		}
		for (int i = idx; i >= 1; i--) {
			if (arr[i][6] != arr[i - 1][2]) r[i - 1] = r[i] * -1;
			else break;
		}
	}
	else {
		for (int i = idx; i >= 1; i--) {
			if (arr[i][6] != arr[i - 1][2]) r[i - 1] = r[i] * -1;
			else break;
		}
	}
}
void rotate() {
	for (int idx = 0; idx < 4; idx++) {
		char temp[8];
		if (r[idx] == 1) { // 시계방향
			for (int i = 1; i < 8; i++) {
				temp[i] = arr[idx][i - 1];
			}
			temp[0] = arr[idx][7];
			for (int i = 0; i < 8; i++)
				arr[idx][i] = temp[i];
		}
		else if (r[idx] == -1) { // 반시계방향
			for (int i = 0; i < 7; i++) {
				temp[i] = arr[idx][i + 1];
			}
			temp[7] = arr[idx][0];
			for (int i = 0; i < 8; i++)
				arr[idx][i] = temp[i];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++) cin >> arr[i];
	cin >> k;
	while (k--) {
		for (int i = 0; i < 4; i++) r[i] = 0;
		int i, j;
		cin >> i >> j; r[i-1] = j;
		startRot(i - 1);
		rotate();
	}

	cout << result();
	return 0;
}