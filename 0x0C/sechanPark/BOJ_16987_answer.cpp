/*
[24/02/08] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/16987

* 번호(파일이름) :  BOJ_16987_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 계란으로 계란치기 / 골드 5 / 영겁

* 설명 :
	- 아 귀찮아
* 풀이 :
	1) 손에 계란을 든다
	2) 든 계란이 피가 없으면 안한다
	3) 피가 있으면 칠꺼다, 모든 경우의 수로, 근데 맞는놈이 피없으면 안친다 
	4) 치고 회복한다. 백트랙킹이니깐
	5) 아니 근데 내꺼는 들고 있고, 내꺼 뺴고 나머지들 바라보는 중이라서
	6) 하나도 안치는 경우는 그냥 바로 마지막으로 가서 꺠진 수 계산한다. 
* 기타 :
	- 진짜 너무 어려워서 답봤는데, 문제 잘못읽었음 씹.., 든 계란이 말짱하면 무한정으로 때리는줄 
	- 근데 답 0.1초 보고 풀었는데도 못품 ㅋㅋ 
	- 하나도 안치는 경우 고려안해서 다시 답봄.. 
	- 진짜 이거는 다시풀어라...
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Egg {
	int hp;
	int atk;
};

int res;
int cnt;
Egg egg[8];

void crush_egg(int hand_egg) {
	if (hand_egg >= cnt) {
		int buf = 0;
		for (int i = 0; i < cnt; i++) {
			if (egg[i].hp <= 0)
				buf++;
		}

		res = max(res, buf);

		return;
	}

	if (egg[hand_egg].hp <= 0) {
		crush_egg(hand_egg + 1);
	}
	else {
		int flag = 1;
		for (int i = 0; i < cnt; i++) {
			if (i == hand_egg)continue;
			if (egg[i].hp <= 0)continue;

			egg[hand_egg].hp -= egg[i].atk;
			egg[i].hp -= egg[hand_egg].atk;
			flag = 0;
			crush_egg(hand_egg + 1);

			egg[hand_egg].hp += egg[i].atk;
			egg[i].hp += egg[hand_egg].atk;
		}
		//와 이게 ㅈㄴ 헷갈림, 꺨꺼 없으면 그냥 런치는거임
		//와 이게 왜 필요하면, 위에서 보면 지금 들고 있는 달걀이면 일단 for문에서 제외하고
		//그리고 나 제외하고 나머지들 피만 보니깐, 내 피만 만땅이면 뭐 검사도 안하고 끝남
		//그래서 필요한겨 ㅇㅇ 
		if (flag)
			crush_egg(cnt);
	}
}

int main() {
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int hp, atk;
		cin >> hp >> atk;
		egg[i] = { hp, atk };
	}

	crush_egg(0);

	cout << res;
}