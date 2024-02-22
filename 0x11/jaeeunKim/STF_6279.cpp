#include <iostream>
#include <string>
using namespace std;
/*
	SFT 6279 Lv.3 "스마트 물류"
	https://softeer.ai/practice/6279
    
	그리디...? : 첫번째 로봇부터 왼쪽, 오른쪽 K범위에 있어서 집을 수 있는 부품의 수를 세면 될 거 같다.
*/
int n, k;
int ans = 0;
string arr;
void check(int idx) {
	for (int i = idx - k; i <= idx+k; i++) { // idx-k부터 idx+k까지 순회
		if (i < 0 || i >= n) continue; // Check OOB
		if (arr[i] == 'H') { // 부품이 있다면 
			arr[i] = 'X'; // 집었다고 처리
			ans++;
			return; // 로봇은 한 개의 부품을 받을 수 있으니 return
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cin >> arr;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'P') {
			check(i);
		}
	}
	cout << ans;
}