#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;
/*
    BOJ 11559 Puyo Puyo
    https://www.acmicpc.net/problem/11559
*/
int row = 12, col = 6;
string board[14];
int dist[14][8];
int ans;
int dx[] = { 1, -1, 0,0 };
int dy[] = { 0,0,-1,1 };

void printArr() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}
void printDist() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
void resetDist() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dist[i][j]) dist[i][j] = 0;
        }
    }
}
void tilt() {
    // dist[x][y] != 0 곳은 다 없애서 아래로 댕기기
    for (int j = 0; j < col; j++) {
        int idx = 0;
        queue<char> tmp;
        for (int i = row - 1; i >= 0; i--) {
            if (dist[i][j] != 0) continue;
            tmp.push(board[i][j]);
        }
        for (int x = tmp.size(); x < row; x++)
            tmp.push('.');
        for (int i = row - 1; i >= 0; i--) {
            board[i][j] = tmp.front(); tmp.pop();
        }
    }
}

int bfs(int x, int y) { // board[x][y]가 상하좌우로 몇개 붙어있는지 리턴하는 bfs함수
    int cnt = 1;
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    q.push({ x,y });
    q2.push({ x,y });
    dist[x][y] = cnt;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
            if (dist[nx][ny] != 0) continue;
            if (board[nx][ny] != board[cur.X][cur.Y]) continue;
            if (board[nx][ny] == '.') continue;
            q.push({ nx,ny });
            q2.push({ nx,ny });
            dist[nx][ny] = ++cnt;
        }
    }
    if (cnt < 4) {
        while(!q2.empty()){
            auto cur = q2.front(); q2.pop();
            dist[cur.X][cur.Y] = 0;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < row; i++) {
            cin >> board[i];
    }
    while (1) {
        int flag = 0;
        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') continue;
                if (dist[i][j]) continue;
                if (bfs(i, j) >= 4) flag = 1;
            }
        }
        //printDist();
        if (flag == 0) break;
        // bfs 순회 완료
        tilt();
        ans++;
        resetDist();
        //printArr();
    }
    cout << ans;
}