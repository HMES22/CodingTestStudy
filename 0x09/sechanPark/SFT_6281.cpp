/*
[24/02/19] sechanPark / 0문제
* 출처 : https://softeer.ai/practice/6281

* 번호(파일이름) :  SOFTEER_6281.cpp

* 문제/난이도/시간(커밋 시 첨부) : [SOFTEER] 동계 테스트 시점 예측 / LV.3 / 120분

* 설명 :
    -
* 풀이 :
    1) 아 그냥 그 백준의 빙산 문제랑 똑같이 풀면됨, 사실 상 다를 거 없음
    2) 개 더럽게 풀어서 할 말이 없네 
* 기타 :
    - 처음에 이중 BFS나와서 식겁하고 다시 밀고 푸느라 오래걸림
    - 아니 이거 딱 1케이스만 시간초과 오지게 나서 한 1시간 버렸는데
    - VECTOR 자료형 하나 바꾸니깐 풀렸음
    - 자료형이 시간초과에 영향을 줄 수 있음 OO 최대한 아껴라 뭐든지 
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int res = 0;
vector<vector<int>>v; //2차원 보드 
vector<vector<bool>>vis; //2차원 방문 배열 
queue<pair<int, int>> q; //bfs용 
queue<pair<int, int>> q_air; //air_bfs용 



int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };



//초기 공기 검사요 
void bfs_air(int x, int y) {

    v[x][y] = 2;
    q.push({ x,y });

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            //if (v[nx][ny] == 2 || v[nx][ny] == 1)continue;  //굳이?
            if (v[nx][ny] != 0)continue;

            v[nx][ny] = 2;
            q.push({ nx, ny });
        }
    }
}

int bfs() {
    int buf = 0;
    //방문 검사 초기화 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1 && vis[i][j] == 0) {
                buf++;
                vis[i][j] = 1;
                q.push({ i,j });

                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    int flag = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue; //어차피 벽에 닿을일 없으니까 빼도 될듯
                        if (vis[nx][ny] == 1 || v[nx][ny] == 0)continue;

                        if (v[nx][ny] == 2) {
                            flag++;
                        }

                        if (v[nx][ny] == 1) {
                            vis[nx][ny] = 1;
                            q.push({ nx, ny });
                        }

                    }
                    if (flag >= 2) {
                        v[cur.first][cur.second] = 0;
                        q_air.push({ cur.first, cur.second });
                    }
                }
            }
        }
    }

    return buf;
}

void fill_air() {

    while (!q_air.empty()) {
        auto cur = q_air.front(); q_air.pop();
        v[cur.first][cur.second] = 2;

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue; //어차피 벽에 닿을일 없으니까 빼도 될듯
            if (v[nx][ny] == 2 || v[nx][ny] == 1)continue;

            v[nx][ny] = 2;
            q_air.push({ nx, ny });
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    v.assign(n, vector<int>(m, 0));
    vis.assign(n, vector<bool>(m, 0));

    //입력 받고 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool b; cin >> b;
            v[i][j] = b;
        }
    }

    //공기 부분 bfs; 
    bfs_air(0, 0);

    while (1) {
        int flag = bfs();
        if (flag) {
            res++;
            fill_air();
        }
        else {
            break;
        }
    }

    cout << res;
}