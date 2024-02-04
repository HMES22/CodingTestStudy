#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 12100 2048(Easy)
	https://www.acmicpc.net/problem/12100

	tilt함수는 왼쪽으로 보드를 땡기는 함수이다.
	오른쪽, 위, 아래쪽으로 기울이는 함수를 따로 구현하지 않은 이유는
	보드 자체를 90도씩 회전하여 왼쪽으로 기울이면 아래, 오른, 위쪽을 다 구할 수 있다.

	하지만, 그렇게 회전하여 왼쪽으로 땡긴 결과자체는 원래 보드를 회전한 것과 같아서
	우리가 생각한 게임방식과는 다른 결과값이 나온다.
	생각한 대로 보드를 만들려면, tilt함수에서 마지막에 다시 원래대로 회전을 시켜줘야 한다.
		예를들어 아래방향은 시계방향 90도 회전후 왼쪽으로 땡기기 때문에, 다시 반시계방향으로 90도 회전해야 한다.
	하지만 문제 자체가 보드 전체의 값을 다 확인하는게 아닌, 최대 원소값을 구하는 것이기 때문에
	다시 보드를 회전할 필요가 읎다.
*/
int n;
int arr[21][21];
int tmp[21][21];
void rotate() {
	int res[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[j][n - i - 1] = tmp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = res[i][j];
		}
	}
}
void tilt(int dir) {
	while (dir--) {
		rotate(); // dir: 0(왼) 1(아래) 2(오른) 3(위)
	}
	for (int i = 0; i < n; i++) {
		int tilted[21] = {};
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] == 0) continue;
			if (tilted[idx] == 0) {
				tilted[idx] = tmp[i][j];
			}
			else if (tilted[idx] == tmp[i][j]) {
				tilted[idx++] *= 2;
			}
			else {
				tilted[++idx] = tmp[i][j];
			}
		}
		for (int j = 0; j < n; j++) tmp[i][j] = tilted[j];
	}
}

void reset() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int max_ = 0;
	for (int num = 0; num < (1 << 10); num++) {
		reset();
		int tnum = num;
		for (int i = 0; i < 5; i++) {
			int dir = tnum % 4;
			tnum /= 4;
			tilt(dir);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				max_ = max(max_, tmp[i][j]);
			}
		}
	}
	cout << max_;
}