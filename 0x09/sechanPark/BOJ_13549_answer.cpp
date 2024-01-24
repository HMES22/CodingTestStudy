/*
* 출처 : https://www.acmicpc.net/problem/13549

* 문제/난이도 : 숨바꼭질 3 / 골드 5

* 설명 : 
	- 수빈이랑 동생이 있는데 수빈이가 동생 찾으러감
	- 수빈이 초능력자라 좌우 이동 1초만에 1칸씩 가능하고
	- 0초 만에 현재 index *2 위치로 이동 쌉가능 
	- 몇 초만에 찾을까?

* 풀이 :
	1) 수빈이 0초만에 갈 수 있는 곳 다 찍음
	2) 찍으면서 서브 큐에서 돌리고 찾은 포인트는 메인 큐에도 넣음
	3) 1초만에 갈 수 있는 곳 다 찍으면서 bfs 
	4) 동생 위치 까지 돌아댕김 

* 기타 :
	- 1번 틀렸는데 7퍼에서 
	- 반례 찾다가 모르고 답 봐버림.. 
	- 한 50분 걸림, 전에 푼 숨바꼭질이랑 비슷
*/


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; 

int vis[100'001]; 
int dx[] = {0, -1, 1}; 

int res = 0; 
int flag = 0; 

int main() {
	int n, k; 
	cin >> n >> k;
	queue<int> q; 

	vis[n] = 1; 
	q.push(n);
	
	while (!flag){
		int cur = q.front(); q.pop(); 
		if (cur == k) {
			res = vis[cur]-1; 
			flag = 1; 
			break; 
		}
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				queue<int>bq; 
				bq.push(cur); 
				while (!bq.empty()){
					int cur = bq.front(); bq.pop(); 
					

					int nx = cur*2;
					if (nx < 0 || nx >= 100'001)continue;
					if (vis[nx] != 0)continue;

					vis[nx] = vis[cur];
					bq.push(nx);
					q.push(nx); 
				}
			}
			else {
				int nx = cur +dx[i];
				if (nx < 0 || nx >= 100'001)continue;
				if (vis[nx] != 0)continue;

				vis[nx] = vis[cur]+1;
				q.push(nx);
			}
		}
	}
	cout << res; 
}