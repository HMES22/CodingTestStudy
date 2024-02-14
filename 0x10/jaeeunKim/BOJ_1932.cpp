#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 1932 실버1 정수 삼각형
    https://www.acmicpc.net/problem/1932
    
	1. 테이블 정의
		d[i][j] : i번째 줄의 j번째에 해당되는 값까지 최대 합
	
	2. 점화식 정의
		if(0 <= j-1 < n && 0<= j+1 < n)
			d[i][j] = max(d[i-1][j-1] , d[i-1][j+1]) + arr[i][j]
		else if(j == 0)
			d[i][j] = d[i-1][0] + arr[i][j]
		else if(j == k) 현재 줄의 마지막 값
			d[i][j] = d[i-1][k-1] + arr[i][j]
	3. 초기값 정의
		d[0][0] = 입력의 첫번째 값
*/
int n;
int arr[501][501];
int d[501][501];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	d[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0)
				d[i][j] = d[i - 1][0] + arr[i][j];
			else if (j == i)
				d[i][j] = d[i - 1][j - 1] + arr[i][j];
			else
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j];
		}
	}
	cout << *max_element(d[n - 1], d[n - 1] + n);

}