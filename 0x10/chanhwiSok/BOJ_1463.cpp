//간단한 재귀 예제

#include<bits/stdc++.h>
using namespace std;

int x;
int dp[1000001];


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cin >> x;
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);

	}
	cout << dp[x];

}