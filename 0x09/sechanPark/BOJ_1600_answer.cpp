/*
* 출처 : https://www.acmicpc.net/problem/1600

* 번호 : 1600

* 문제/난이도/시간 : [BOJ] 말이 되고픈 원숭이 / 골드3 / 90분

* 설명 :
	- 원숭이는 말이, 홀스가 되길 원했댕, 그래서 말의 움직임을 스윽 보니
	- 체스의 나이트처럼 움직이더라 이말이지.. 
	- 그치만 난 원숭이인걸? 오직 k번만 이렇게 움직이고 그 외에는 상하좌우만 가능한겨
	- 처음에 k, 이후 열, 행을 입력으로 준다. / 0은 갈수있고 1은 벽
	- 도착점 까지 못가면 -1 출력, 과연 언숭이는 말이 될수 있을것인가?

* 풀이 :
	1)일단 껑충횟수k, 열 행 입력 받아서 board 채우고 
	2)시작점 고정이니깐 껑충 가능 횟수 들어간 3차원 방문 기록하고 큐 돌림
	3)큐 돌리면서 껑충 여부에 따라서 맵 바꿔서 방문 표시 
	4)그냥 벽부수며가는 bfs문제랑 비슷함 

* 기타 :
	- 시이발.. 1시간 보다가 3퍼에서 막혀서 반례만 봄 ㄹㅇ 손가락 다걸고
	- 반례 보다가 잘 못된거 띠용함 
	- 깡총으로 먼저 들어간 놈들때문에 걸어가서 깡총 할 수가 없어진 상황임 
	- 이거 숨바꼭질이랑 다르게 1차원이 아니라 점프가 무조건 빨리 간다는 보장이 없음, 그래서 벽뿌수는거 마냥 풀어야함 
*/

#include <iostream>
#include <queue> 
#include <algorithm>  
#include <tuple> 
using namespace std; 

int k; 
int n, m; 
bool board[200][200]; 
int vis[200][200][31];

int dx[12] = { 2, 2, 1, 1, -2, -2, -1, -1, 0, 0, 1, -1};
int dy[12] = { 1, -1, 2, -2, 1, -1, 2, -2, 1, -1, 0, 0};

bool flag = 0; 
int res = -1;

int main() {
	cin >> k; 
	cin >> m >> n; 

	//일단 다 입력 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool x; 
			cin >> x; 
			board[i][j] = x; 
		}
	}

	queue<tuple<int, int, int>> q; // x, y, 껑충 여부
	vis[0][0][k] = 1; 
	q.push({ 0,0,k }); 

	while (!q.empty() && flag == 0){
		int x, y, jump; 
		tie(x, y, jump) = q.front(); q.pop(); 

		if (x == n - 1 && y == m - 1) {
			flag = 1; 
			res = vis[x][y][jump] - 1; 
			continue; 
		}

		for (int i = 0; i < 12; i++) {
			int nx, ny;
			int njump = jump;

			if (i < 8 && jump == 0) {
				continue; 
			}
			else if (i < 8 && jump > 0) {
				njump = jump - 1;
			}

			nx = x + dx[i]; 
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue; 
			if (board[nx][ny] == 1)continue; 
			if (vis[nx][ny][njump] != 0)continue; 

			vis[nx][ny][njump] = vis[x][y][jump] + 1; 
			q.push({ nx, ny, njump }); 

		}
	}
	cout << res; 
}

