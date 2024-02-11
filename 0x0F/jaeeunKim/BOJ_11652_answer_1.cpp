#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	BOJ 11652 카드
	https://www.acmicpc.net/problem/11652
*/
using ll = long long;
int n;
ll arr[100'001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll prev = arr[0];
	int cnt = 0; // 현재 수가 몇번 등장
	ll mxVal = -(1 << 62) - 1; // 현재까지 가장 많이 등장한 수의 값
	int mxCnt = 0; // 현재까지 가장 많이 등장한 수의 count 값
	for (int i = 0; i < n; i++) {
		if (i == 0 || arr[i-1] == arr[i]) {
			++cnt;
		}
		else{
			if (mxCnt < cnt){
				mxVal = arr[i-1];
				mxCnt = cnt;
			}
			cnt = 1;
		}
	}
	if(cnt > mxCnt) mxVal = arr[n-1];
	cout << mxVal;
}
