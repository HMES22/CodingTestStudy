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
		if (prev == arr[i]) {
			++cnt;
		}
		else{
			if (mxCnt < cnt)
				mxVal = prev;
			else if (mxCnt == cnt)
				mxVal = min(mxVal, prev);
			
			mxCnt = max(cnt, mxCnt);
			cnt = 1;
		}
		if (i == n - 1) {
			if (mxCnt < cnt)
				mxVal = prev;
			else if (mxCnt == cnt)
				mxVal = min(mxVal, prev);
			mxCnt = max(cnt, mxCnt);
			cnt = 1;
		}
		prev = arr[i];
	}
	cout << mxVal;
}
