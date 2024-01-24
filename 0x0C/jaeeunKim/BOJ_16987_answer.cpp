#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 16987 계란으로 계란치기
    https://www.acmicpc.net/problem/16987

*/
int n;
int s[10], w[10]; // pair를 굳이 안써도 됨!
int mx = 0;
int cnt = 0; // 깨진 계란의 수

void solve(int a){ // a번째 계란으로 다른 걸 깰 차례다
    if(a == n){  // 제일 오른쪽의 계란을 기준으로 치는 경우까지 도달했다면
        mx = max(mx, cnt); // 현재
        return;
    }

    //현재 a번째 계란이 깨져있거나, a계란 빼고 다 깨졌다면?
    if(s[a] <= 0 || cnt == n-1){ 
        solve(a+1); // a+1번째 계란으로 다른 걸 깨부수기
        return;
    }
    for(int t =0; t < n; t++){ // t번째 계란과 뿌셔보자
        // t가 a이거나, t번째 계란이 깨진 경우는 pass
        if(t == a or s[t] <= 0) continue;

        // a번째 계란과 t번째 계란을 부딪혀
        s[a] -= w[t];
        s[t] -= w[a];

        // 깨진 계란 count
        if(s[a] <= 0) cnt++;
        if(s[t] <= 0) cnt++;
        
        solve(a+1); // 하나를 쳤으니, 문제의 3의 조건으로 한칸 오른쪽의 계란으로 다른걸 깰 차례!

        // 원상 복귀시키기
        if(s[a] <= 0) cnt--;
        if(s[t] <= 0) cnt--;
        s[a] += w[t];
        s[t] += w[a];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i< n; i++)
        cin >> s[i] >> w[i];
    solve(0);
    cout <<mx;
}