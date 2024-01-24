#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 1941 소문난 칠공주
  https://www.acmicpc.net/problem/1941

  1. 25명 중에 7명 선택 (next_permutation 사용)
	1-1. 인접한 자리에 속하는 지 확인하기 위해, BFS로 검사할 것
	1-2. 7명중 한명만 큐에 삽입
  2. 7명이 모두 인접한 자리에 속하고, 다솜파 수가 4명 이상인 경우 ans++
	2-1. 큐에 있는 학생을 기준으로 BFS 순회
	2-2. 모두 인접한 자리에 있다면, 순회한 학생의 수가 7명 이상일 것
*/
string arr[5];
bool mask[25];
int ans;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 5; i++)
    cin >> arr[i];
  fill(mask + 7, mask + 25, true); // 7명만 false(0)

  do {
    queue<pair<int, int>> q;
    int dasom = 0; // 구성원 중 이다솜 파의 수
    int adj = 0; // 가로세로로 인접한 사람의 수
    bool isp7[5][5] = {};
    bool vis[5][5] = {};

    // 25명중 7명을 일단 뽑아서 큐에 삽입
    for (int i = 0; i < 25; i++) {
      if (!mask[i]) {
        int x = i / 5, y = i % 5;
        isp7[x][y] = true;
        if (q.empty()) {
          q.push({ x,y });
          vis[x][y] = true; // 시작점만 큐에 삽입
        }
      }
    }

    while (!q.empty()) {
      int x, y;
      tie(x, y) = q.front();
      q.pop();
      adj++;
      dasom += (arr[x][y] == 'S');
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (vis[nx][ny] || !isp7[nx][ny]) continue; // 이미 방문했거나, 7명에 속하지 않는 경우
        q.push({ nx,ny });
        vis[nx][ny] = true;
      }
    }
    ans += (adj >= 7 && dasom >= 4);

  } while (next_permutation(mask, mask + 25));
  cout << ans;
}