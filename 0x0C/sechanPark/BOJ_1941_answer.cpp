/*
[24/02/07] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/1941

* 번호(파일이름) :  BOJ_1941_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 소문난 칠공주 / 골드 3 / 100분

* 설명 :
	-  5*5 배열에 S와 Y가 있음
	- S는 칠공주 결정을 위해서 인접해서 존재해야함
	- Y 포함하여 4명이상은 S가 있어야 7공주 완성
	- 가능한 7공주 경우의 수를 출력 

* 풀이 :
	1) 임의로 7명을 뽑고 
	2) 7명이 인접한지 확인하고
	3) 인접하면 S가 몇명인지 확인해서 결과 증가 
* 기타 :
	- 처음에는 S포인트 마다 DFS를 해서 방문여부 판단해서 깊이 탐색 할라했음
	- 근데 이게 한방향으로 쭉 이동해버리니깐 경우의 수가 좀 꼬임 
	- 그렇다고 방문찍어놓고 유지하면 또 경우의 수가 꼬이고
	- 참다 참다 답 봐버림.......힝
	- 방법론만 봄, 가슴의 손을 얹고 

	- 진짜 돌아버려, 조합은 1차원으로 하고, dfs는 2차원으로 하니까 돌아버렸음 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char board[5][5];
bool vis[5][5]; 

int dx[] = { 0, 1, 0, -1 }; 
int dy[] = { 1, 0, -1, 0 };

int res; 

vector<pair<int, int>> v;
vector <int> v2; 

int depth; 
int s; 

int main() {
	//25명 받고 
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char c; cin >> c;
			board[i][j] = c;
		}
	}

	//조합 용 벡터 설정 
	v2.assign(25, 1); 
	for (int i = 0; i < 7; i++) {
		v2[i] = 0; 
	}

	do {
		//v.clear();
		for (int i = 0; i < 5; i++) {
			fill(vis[i], vis[i] + 5, 1);
		}
	 
		depth = 1; 
		s = 0; 

		int flag = 1; 
		for (int i = 0; i < 25; i++) {
			if (v2[i] == 0) {
				if (flag) {
					v.push_back({ i / 5 , i % 5 });
					vis[i/5][i%5] = 1;
					flag = 0;
				}
				else {
					vis[i / 5][i % 5] = 0;
				}
				if (board[i / 5][i % 5] == 'S') {
					s++; 
				}
			}
		}

		//인접한지 확인 
		//한 포인트 부터 dfs로 이어짐 확인 
		while (!v.empty()){
			auto cur = v.back(); v.pop_back(); 
			
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i]; 
				int ny = cur.second + dy[i]; 

				if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)continue; 
				if (vis[nx][ny] != 0 )continue;

				vis[nx][ny] = 1;
				v.push_back({nx, ny});
				
				depth++;
			}
		}

		if (depth ==  7) {
			if (s >= 4) {
				res++; 
			}
		}

	} while (next_permutation(v2.begin(), v2.end()));

	cout << res; 
}