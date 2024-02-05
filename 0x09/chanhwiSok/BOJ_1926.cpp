/*
바킹독 BFS 기본 문제
BFS 처음 배워서 외우는 게 아직 안됨.. 결국 그냥 따라침.


막힌 부분 : 따라쳤는데도 답안나와서 이리저리 보다가 알아 낸것 .. 
!!!!!매크로 사용 시에 세미콜론 쓰면 안됨!!!!!

문제 핵심 : BFS 기본 형식에서 제일 커다란 부분과 이어진 것들의 갯수 카운트 하는 것 추가..

이어진 것들의 갯수 = 시작점 

제일 커다란 부분(공간의 넓이) = POP 하면서 카운트

안보고 다시 풀어보자...
*/

#include <bits/stdc++.h>
using namespace std;
#define X first               //매크로 사용시에 세미콜론 쓰지말기!!!
#define Y second			//그냥 따라쓰기만 했는데 안되서 개고생함ㅠㅠ

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[502][502];
int vis[502][502];


int main() {
	freopen("input.txt", "r", stdin);


	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int num = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {  //(i,j)를 시작점으로 하고 싶음.
			if (board[i][j] == 0 || vis[i][j]) continue;

			num++; // 이해가 좀 안됬던 부분 왜 여기서 그림 추가??
			//==> 시작점을 정하는 부분이고 시작점 정해졌을 때, 그림하나가 생긴다 생각하면 됨!
			//==> 위의 if 조건으로 인해, 이어진 부분은 안됨

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0;

			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;

					vis[nx][ny] = 1;

					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area);
		}
		
	}
	cout << num << '\n' << mx;


}
