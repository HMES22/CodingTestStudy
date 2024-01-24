/*
* 출처 : https://www.acmicpc.net/problem/2146

* 문제 : 다리 만들기 / 골드 3 

* 설명 : N x N 지도 위에 섬이 있고, 섬을 잇는 가장 짧은 다리를 구하라 

* 풀이 : 
	1) 섬 마다 넘버링 하여 섬을 구분 짓는다 
	2) 섬 수 만큼 반복문을 돌껀데, 돌면서 다른섬 만나면 최소값 갱신한다 
	3) 싹다 돌면 끝 

* 기타 : 
	- 시간 50분 걸림 
	- 보고 품, 한번 스을쩍 보고 푼듯? 
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 

int board[100][100];			//입력 저장
int vis[100][100];				//방문 저장 

int dx[] = { 0, 0, 1, -1 };		//상하좌우 이동용 
int dy[] = { 1, -1, 0, 0 }; 

int res = 0;					//결과 값 저장
int first_flag = 0;				//초기 들어가는 결과 값 확인 용 

int main() {
	int n; cin >> n;		
	//일단 싹다 입력 받음 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x; 
			board[i][j] = x; 
		}
	}

	//입력 받은거 돌면서 섬마다 넘버링 다르게 함 
	int land = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				land++; 
				queue<pair<int, int>>q;
				vis[i][j] = 1;
				board[i][j] = land; 
				q.push({ i,j });
				while (!q.empty()){
					auto cur = q.front(); q.pop(); 
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i]; 
						int ny = cur.second + dy[i]; 

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue; 
						if (vis[nx][ny] != 0 || board[nx][ny] == 0)continue; 

						board[nx][ny] = land;
						vis[nx][ny] = 1; 
						q.push({ nx,ny }); 
						
					}
				}
			}
		}
	}
	//디버깅용 끄적
	/*
	cout << "\n" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << "\n";
	*/

	//섬 확인용 
	int land_buf = 0;	
	//섬 수만큼 반복문 돌림 
	while (land--){		
		queue<pair<int, int>>q; 
		land_buf++;									// 1번 섬 부터 시작요 

													//방문 초기화 및 방문 할꺼 큐에 떄려박음 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = 0;
				if (board[i][j] == land_buf) {
					vis[i][j] = 1; 
					q.push({ i,j }); 
				}
			}
		}

		while (!q.empty()){
			auto cur = q.front(); q.pop(); 
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;		//범위 체크용 
				if (vis[nx][ny] != 0)continue;								//방문 한거 제낌

				if (board[nx][ny] != land_buf && board[nx][ny] != 0) {		//육지인데? 내 섬은 아닌놈, 근데 위에서 방문 처리 해서 내가 내섬을 찍을 일은 없을듯.. 
					if (!first_flag) {										//초기값 이면, 최소 값 초기화 
						first_flag = 1;
						res = vis[cur.first][cur.second]; 
					}
					else {
						if (vis[cur.first][cur.second] < res) {				//최소 보다 작으면 갱신 
							res = vis[cur.first][cur.second];
						}
					}
					continue;												//다리 놓으면 방문 X, 근데 이럴꺼면 그냥 break 해도 될듯? 
				}

				vis[nx][ny] = vis[cur.first][cur.second] + 1;
				q.push({ nx,ny }); 
			}
		}
		/*
		for (int i = 0; i < n; i++) {										//디버깅용 끄적
			for (int j = 0; j < n; j++) {
				cout << vis[i][j] << " ";
			}
			cout << "\n";
		}
		cout << res << "\n"; 
		*/
	}

	cout << res-1;				//출력 ㅇㅇ 
}