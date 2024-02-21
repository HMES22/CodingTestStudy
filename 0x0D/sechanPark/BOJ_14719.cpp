/*
[24/02/21] sechanPark / 2문제
* 출처 : https://www.acmicpc.net/problem/14719

* 번호(파일이름) :  BOJ_14719.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 빗물 / 골드 5 / 30분

* 설명 :
	- 진짜 그릇에 물 붓는다고 생각하고 푸셈
* 풀이 :
	1) 현재 위치 기준에서 양쪽을 다 살펴보면서 물이 얼마나 고일지 판단함
	2) 중간에 굴곡 있든 없든 의미없음, 결국에 더 큰 벽 만나면 그만큼 채워지니깐 
	3) 훼이크에 속지마셈 
	4) 양쪽 만나는 큰벽 중에서 가장 작은 벽 만큼 물이 줄줄 샐꺼니깐 작은 벽이랑 내 높이랑 비교하면됨 
	5) 이제 중간중간에 최적화 해주면 되는데, 
	6) 어차피 양 끝벽은 없으면 물이 고일 수 없어서 패스
	7) 내가 벽만큼 높아도 안고임 패스 
	8) 양 끝벽 높이랑 내 높이랑 뺴버리니깐 음수가 나오기도 함, 그거 처리 
* 기타 :
	- 진짜 옛날에 풀어봐서 금방푼듯.... 처음이면 고생했을 듯..... 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hight, width;
vector<int>world; 
int water = 0; 
int main() {
	cin >> hight >> width; 

	for (int i = 0; i < width; i++) {
		int x; cin >> x;
		world.push_back(x); 
	}

	for (int i = 0; i < width; i++) {
		if (i == 0)continue; //끝에는 물이 못고임
		if (i == width - 1)continue; 
		if (world[i] == hight)continue; //최대로 높으면 물 못고임 
		int cur = i; 
		int L_max = 0; 
		int R_max = 0; 

		//move left
		for (int left = cur - 1; left >= 0; left--) {
			L_max = max(L_max, world[left]);
		}
		//move right
		for (int right = cur + 1; right < width; right++) {
			R_max = max(R_max, world[right]);
		}
		
		int buf = min(L_max, R_max) - world[cur];

		if (buf > 0) {
			water += buf; 
		}
	}

	cout << water; 
}