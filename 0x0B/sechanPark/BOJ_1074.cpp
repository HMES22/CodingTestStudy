/*
[24/01/30] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/1074

* 번호(파일이름) :  BOJ_1074.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] / 실버 1 / 120분

* 설명 : 
    - 2의 N승을 한변으로 하는 배열을 Z모양으로 탐색한다 
    - N > 1인 경우는 4등분으로 쪼개서 Z모양으로 탐색한다
    - N과 행 열이 주어지고, 해당 칸을 몇 번째에 방문하는지 출력하라 
* 풀이 :
    1) 목표하는 행 열에 도착하면 출력하고 리턴한다.
    2) N > 1이면 4등분으로 계속 쪼갠다 
    
    3) 재귀 함수에 N과 행, 열, 2의 N-1승, 방문순서를 파라미터로 사용
    4) 4등분으로 쪼갤때, 4가지 포인트의 Z시작점에 대한 행, 열, 방문횟수 지정은 다음과 같음
    5) 행 열 : 현재 행 열에서 쪼개질 네모의 한변 크기만큼 증가 
    6) 방문횟수 : 쪼개질 네모 한변의 제곱 만큼임
    7) 위의 것들, 누적하면서 이동하면됨 

* 기타 :
    - 이게 맞는지 모르겠다.. 그냥 막쓰다 보니까 지저분 하게 된듯
    - 시간 초과가 개 많이 떴는데, 감도 못잡다가 재귀가 불필요하게 너무 많이해서 그랬던걸 알게됨..
    - 결국은 분할정복 했어야 하는 문제였음.. ㄷㄷ
*/

#include <iostream>
using namespace std;

int n;
int m;

void Z_func(int N, int r, int c, int N2, int res) {
    
    if (r == n && c == m) {
        cout << res << "\n";
        return;
    }
   
    if (N >= 1) {
        int N22 = N2 * N2;
        if ((n >= r && n <= r+N2) || (m >= c && m <= c+N2))                             Z_func(N - 1, r, c, N2 / 2,res);
        if ((n >= r && n <= r + N2) || (m >= c + N2 && m <= c + N2 + N2))               Z_func(N - 1, r, c + N2, N2 / 2, res+ N22*1);
        if ((n >= r + N2 && n <= r + N2 + N2) || (m >= c && m <= c + N2))               Z_func(N - 1, r + N2, c, N2 / 2, res + N22 * 2);
        if ((n >= r + N2 && n <= r + N2 + N2) || (m >= c + N2 && m <= c + N2 + N2))     Z_func(N - 1, r + N2, c + N2, N2 / 2, res + N22 * 3);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N >> n >> m;

    int N2 = 1;
    for (int i = 0; i < N - 1; i++) {
        N2 *= 2;
    }

    Z_func(N, 0, 0, N2,0);
}