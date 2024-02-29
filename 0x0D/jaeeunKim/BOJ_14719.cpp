#include <iostream>
#include <vector>
using namespace std;
/*
	BOJ 14179 골드5 "빗물"
	https://www.acmicpc.net/problem/14719

	5 5
	5 1 2 1 5
	
	11
*/
int h, w;
int arr[501][501]; // w * h 임. 반대로 생각하기
int ans;

int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int tmp;
		cin >> tmp;
		fill(arr[i], arr[i] + tmp, 1);
	}

	for (int i = 0; i < h; i++) {
		int flag = 0;
		int cnt = 0;
		for (int j = 0; j < w; j++) {
			if (flag == 0 && arr[j][i] == 1) { // 처음 1을 찾은 경우 flag = 1
				flag = 1;
			}
			else if (flag >= 1 && arr[j][i] == 0) { // 1다음에 있는 0들을 일단 count, flag = 2로 설정
				cnt++;
				flag = 2;
			}
			else if (flag == 2 && arr[j][i] == 1) { // 0을 세다가 1을 만났다면, 지금까지 count한 0은 1로 둘러싸인 것임
				ans += cnt;
				cnt = 0;
				flag = 1; 
			}
		}

	}
	cout << ans;
	return 0;
}
