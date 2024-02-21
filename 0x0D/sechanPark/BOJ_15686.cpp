/*
[24/02/21] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/15686

* 번호(파일이름) :  BOJ_15686.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 치킨 배달 / 골드 5 / 30분

* 설명 :
	- NxN의 도시에 사람(1)과 치킨집(2)이 있다. 
	- 사람에서 치킨집 까지의 거리를 치킨거리라 하고, 가장 가까운 치킨거리를 치킨거리라 생각한다.
	- 치킨집 중에서 최대 M개의 치킨집만 살아남는 상황에서
	- 도시의 치킨거리 총합이 가장작게 하는 경우를 구해라 
* 풀이 :
	1) 먼저 총 치킨집 중에서 M개만 택하는 경우의 수 함수를 구현(어차피 치킨거리를 줄이려면 다다 익선 이니깐)
	2) 치킨집 리스트업 할때마다 모든 사람들을 다 훝어서 치킨거리를 구함 
	3) 치킨거리가 MIN값을 치킨집 리스트업 할때마다 갱신
	4) 최종적으로 도시의 치킨거리 MIN을 갱신 
* 기타 :
	- 간만에 원트해서 기분 너무좋다.. 김호..찌...
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

vector<pair<int, int>>chick_xy; 
vector<pair<int, int>>human_xy;
vector<int> combi_arr; 
int N, M; 
int res = 99999; 

void chosenChick(); 

int main() {
	
	cin >> N >> M; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x; cin >> x; 
			if (x == 1) {
				human_xy.push_back({ i, j }); 
			}
			else if (x == 2) {
				chick_xy.push_back({ i, j });
				combi_arr.push_back(1); 
			}
		}
	}

	for (int i = 0; i < M; i++) {
		combi_arr[i] = 0; 
	}
	
	chosenChick(); 

	cout << res; 
	
}

void chosenChick() {
	//여기서 모든 치킨집에서 M개만 뽑는 짓을 할꺼임 
	//do 한번이 경우의 수 1번이라고생각하면됨 
	
	do {
		vector<int> chick_range;
		chick_range.assign(human_xy.size(), 99999);
		for (int i = 0; i < combi_arr.size(); i++) {
			if (combi_arr[i] == 0) {
				auto cur_chick = chick_xy[i]; 
				int C_x = cur_chick.first; 
				int C_y = cur_chick.second; 
				//사람 경우의 수 다돌림? 
				for (int j = 0; j < human_xy.size(); j++) {
					auto cur_human = human_xy[j];
					int H_x = cur_human.first; 
					int H_y = cur_human.second; 

					int range = abs(H_x - C_x) + abs(H_y - C_y); 
					chick_range[j] = min(range, chick_range[j]); 
				}
			}
		}
		int buf = 0; 
		for (int i = 0; i < chick_range.size(); i++) {
			buf += chick_range[i]; 
		}
		res = min(res, buf); 
	} while (next_permutation(combi_arr.begin(), combi_arr.end()));
}