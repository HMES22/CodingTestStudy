#include <iostream>
#include <algorithm>
using namespace std;
/*
    BOJ 실버2 연속합 
    https://www.acmicpc.net/submit/1912/74214979

    1. 테이블 정의
        dp[x] = x번째 항으로 끝나는 연속합
    2. 점화식 정의
        dp[x] = max(dp[x-1] + num[x], num[x])
    3. 초기값 정의
        dp[0] = num[0];
    
    어떻게든 DP로 풀려고 별 지랄을 다했지만 내가 푼 DP방식도 N*N이라서 시간초과가 떴다.
    ★ 나를 포함한 지금까지의 합과 나 자신을 비교하는 것이 포인트 ★
*/
int a[100'003];
int dp[100'003];
int main(){
    int n;
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    dp[0] = a[0];
    for(int i = 1; i<n; i++){
        dp[i] = max(dp[i-1] + a[i], a[i]);
    }
    cout << *(max_element(dp, dp+n));
}