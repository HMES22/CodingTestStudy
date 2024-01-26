#include <cmath>
#include <iostream>
using namespace std;
/*
    BOJ 15684 감시
    https://www.acmicpc.net/problem/15683

*/
int n, m;
int arr[9][9];
int ans = 81;
int camX[9], camY[9];
int degcase[9];

int countZero() { // Count 사각 지대 수
    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!arr[i][j])
                num++;
    return num;
}

void reset() { // CCTV 시야 처리 비활성화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 9)
                arr[i][j] = 0;
        }
    }
}

void print() { // 디버깅용 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

void right(int x, int y) { // (x,y) 위치의 CCTV를 기준으로 오른쪽 시야 처리
    for (int i = y + 1; i < m; i++) {
        if (i < 0 || i >= m) continue;
        if (arr[x][i] == 6)
            break;
        if (!arr[x][i])
            arr[x][i] = 9;
    }
}
void left(int x, int y) { // (x,y) 위치의 CCTV를 기준으로 왼쪽 시야 처리
    for (int i = y-1; i >= 0; i--) {
        if (i < 0 || i >= m) continue;
        if (arr[x][i] == 6)
            break;
        if (!arr[x][i])
            arr[x][i] = 9;
    }
}
void top(int x, int y) { // (x,y) 위치의 CCTV를 기준으로 위쪽 시야 처리
    for (int i = x-1; i >= 0; i--) {
        if (i < 0 || i >= n) continue;
        if (arr[i][y] == 6)
            break;
        if (!arr[i][y])
            arr[i][y] = 9;
    }
}
void bottom(int x, int y) { // (x,y) 위치의 CCTV를 기준으로 아래쪽 시야 처리
    for (int i = x + 1; i < n; i++) {
        if (arr[i][y] == 6)
            break;
        if (!arr[i][y])
            arr[i][y] = 9;
    }
}

void cctv(int cam, int deg) {  // cam 번째 카메라의 deg회전하여 arr에 CCTV 시야 처리(arr값을 9로 처리)
    int x = camX[cam];
    int y = camY[cam];

    if (arr[x][y] == 1) {
        if (deg == 0) // 우
            right(x, y);
        else if (deg == 1) // 하
            bottom(x, y);
        else if (deg == 2) // 좌
            left(x, y);
        else //  상
            top(x, y);
    }
    else if (arr[x][y] == 2) {
        if (deg == 0 || deg == 2) { // 좌우
            left(x, y);
            right(x, y);
        }
        else if (deg == 1 || deg == 3) { // 상하
            top(x, y);
            bottom(x, y);
        }
    }
    else if (arr[x][y] == 3) {
        switch (deg) {
        case 0:
            right(x, y);
            top(x, y);
            break;
        case 1:
            right(x, y);
            bottom(x, y);
            break;
        case 2:
            left(x, y);
            bottom(x, y);
            break;
        case 3:
            left(x, y);
            top(x, y);
            break;
        }
    }
    else if (arr[x][y] == 4) { //
        switch (deg) {
        case 0:
            top(x, y);
            right(x, y);
            left(x, y);
            break;
        case 1:
            top(x, y);
            right(x, y);
            bottom(x, y);
            break;
        case 2:
            bottom(x, y);
            right(x, y);
            left(x, y);
            break;
        case 3:
            top(x, y);
            left(x, y);
            bottom(x, y);
            break;
        }

    }
    else if (arr[x][y] == 5) { //나의 상하좌우
        top(x, y);
        right(x, y);
        left(x, y);
        bottom(x, y);
    }
}

int main() {
    int camCnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) { // CCTV인 경우
                camX[camCnt] = i;
                camY[camCnt] = j;
                ++camCnt;
            }
        }
    }
    for (int t = 0; t < pow(4, camCnt); t++) { // N개이 카메라가 있을 때 4^N가지의 경우가 생김
        int tmp = t;
        for (int c = camCnt - 1; c >= 0; c--) {
            int p = (int)pow(4, c);
            degcase[c] = tmp / p; // 4진수로 처리하여 각 카메라의 각도 경우를 degcase에 저장
            tmp %= p;
        }

        for (int i = 0; i < camCnt; i++) { // 각도의 경우의 수마다 전체 카메라의 시야 처리
            cctv(i, degcase[i]);
        }
        int zero = countZero(); // 사각지대 개수 세기
        ans = min(ans, zero); // 사각지대의 최소값 갱신
        reset(); // 다시 arr 원상복귀
    }
    cout << ans;
}