#include <iostream>
using namespace std;
/*
    BOJ 18808 스티커 붙이기
    https://www.acmicpc.net/problem/18808
*/

int n, m, k;
int arr[41][41];
int paper[101][11][11];
int pCnt[101];
int px[101];
int py[101];

void printPaper(int p) {
    for (int i = 0; i < px[p]; i++) {
        for (int j = 0; j < py[p]; j++)
            cout << paper[p][i][j] << ' ';
        cout << '\n';
    }
}

void print() {
    cout << "===================================\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    cout << "===================================\n";
}

void rotate(int p) { // p번째 색종이 90도 회전!
    int temp[11][11] = { 0 };
    for (int i = 0; i < px[p]; i++) {
        for (int j = 0; j < py[p]; j++)
            temp[i][j] = paper[p][i][j];
    }
    for (int i = 0; i < px[p]; i++) { // 90도 회전
        for (int j = 0; j < py[p]; j++) {
            paper[p][j][px[p] - 1 - i] = temp[i][j];
        }
    }
    int tmp = px[p];
    px[p] = py[p];
    py[p] = tmp;
}

bool OOB(int a, int b) {
    return a < 0 || b < 0 || a >= n || b >= m;
}

int check(int i, int j, int p) {
    // i, j를 시작점으로 색종이 x, y 만큼 검사하기
    int cnt = 0;
    int x = px[p];
    int y = py[p];
    for (int pi = 0; pi < x; pi++) {
        for (int pj = 0; pj < y; pj++) {
            if (OOB(i + pi, j + pj)) continue;
            cnt += (arr[i + pi][j + pj] == 0 && paper[p][pi][pj] == 1);
        }
    }
    return cnt;
}

bool stick(int p) { // 스티커 붙이는 거 가능한가 검사하는 함수
    int x = px[p];
    int y = py[p];
    for (int i = 0; i <= n - x; i++) {
        for (int j = 0; j <= m - y; j++) {
            int cnt = check(i, j, p); //i,j를 시작점으로 p번 색종이를 대봐
            if (cnt == pCnt[p]) { // 붙일 수 있다면?
                // 배치하고 나가기
                for (int pi = 0; pi < x; pi++) {
                    for (int pj = 0; pj < y; pj++) {
                        if(!arr[i+pi][j+pj])
                            arr[i + pi][j + pj] = paper[p][pi][pj];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> px[i] >> py[i];
        for (int rr = 0; rr < px[i]; rr++) {
            for (int cc = 0; cc < py[i]; cc++) {
                cin >> paper[i][rr][cc];
                if (paper[i][rr][cc] == 1) pCnt[i]++;
            }
        }
    }
    // k개의 색종이에 대해서 노트북에 대보면서 검사해봐
    for (int p = 0; p < k; p++) {
        int x = px[p];
        int y = py[p];
        int deg = 0;
        int done = false;
        if (stick(p)) { // 가능하면 다음 걸로
            continue;
        }
        else {
            while (deg < 3) { // 불가능시 최대 3번 회전 가능
                ++deg;
                rotate(p);
                if (stick(p)) break; // 회전한거 붙였으면 다음 스티커로
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans += (arr[i][j] == 1);
    }
    cout << ans;
}
