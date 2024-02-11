#include <iostream>
#include <algorithm>
using namespace std;
/*
	BOJ 2579 실버3 계단 오르기
	https://www.acmicpc.net/problem/2579

	DP 풀이 (1차원 테이블)
    밟은 계단 값의 합이 최대가 되는 경우를 찾는 것은 밟지 않는 계단 값의 합이 최소가 될 경우와 같다
    즉 밟지 않는 계단의 합의 최소를 찾아서, 모든 계단을 밟는 경우의 합산에서 빼면 원래의 답과 같다.
	
    1. 테이블 정의하기
		d[i] = i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최소값,
				단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함
		
	2. 점화식 찾기
		d[k] = min(d[k-2], d[k-3]) + s[k]
        k를 안밟았다는 것은 k-1번째는 무조건 밟았다는 것이다.
        따라서 k-1을 밟으려면 k-2를 안밟거나, k-3을 안밟는 경우 2가지가 생긴다. => 이 두개의 값의 최소값에 현재의 s[k] 값을 더하면 됨!
        
	3. 초기값 설정하기
		d[1] = s[1], d[2] = s[2], d[3] = s[3], d[3]은 1과 3을 안밟거나, 3만 안밟거나 2가지가 생기지만 당연히 3만 밟지 않는 것이 최소기 때문에 d[3] == s[3]
        
*/
int n;
int s[301];
int d[301];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	d[1] = s[1], d[2] = s[2], d[3] = s[3];
	for (int i = 4; i <= n; i++) {
		d[i] = min(d[i - 2], d[i - 3]) + s[i];
	}
	cout << sum - (min(d[n - 1], d[n - 2]));
}