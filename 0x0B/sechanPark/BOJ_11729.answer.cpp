/*
[24/01/29] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/11729

* 번호(파일이름) :  BOJ_11729.answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 하노이 탑 이동 순서 / 골드5 / 60분?

* 설명 : 
	- 입력 받은 블록 수 만큼, 하노이 알고리즘을 수행
	- 최소 이동 횟수와 이동 루트를 출력해라
* 풀이 :
	1) 하노이 게임을 하며 알고리즘 분석
	2) 예를 들어 4개를 옮기는 상황을 가정해 보자
	3) A, B, C의 꼬챙이라고 한다면, 
	4) B에 3개를 옮겨놓고 -> A에서 C로 옮기고 -> C에 3개를 옮기고
	5) 종료 조건은 1개 남으면 이동하고 끝
* 기타 :
	- 진짜 풀다가 뒤져버릴뻔 
	- 약간 재귀적인 지능이 없는 것 같아서, 그냥 답보고 느끼는게 나을듯
	- 중요한건 1)종료 조건 2) 문제 정의? 현상?을 그냥 글쓰듯이 쓰기
	- 핵심은 돌아가는거 신경쓰지 말고 목표만 명시
	- 근데 약간 단편적인 목표만? 약간 뇌빼고 초딩처럼 쓰는?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int res; 

void move(int start,int end) {
	v.push_back({start, end});
	res++; 
}

int hanoi(int n, int start, int other, int end) {
	if (n == 1) {
		move(start, end);
		return 0;
	}
	hanoi(n - 1, start, end, other); //A에서 시작하니깐, 바닥에 깔린거 뺴고 나머지 A놈들을 B로 옮겨라
	move(start, end);				 //A에 1개 남은거 C로 옮겨라
	hanoi(n - 1, other, start, end); //B에 있던거 C로 옮겨라
	return 0;
}

int main() {
	int n; 
	cin >> n; 

	hanoi(n, 1, 2, 3); 

	cout << res << "\n"; 
	for (auto i : v)
		cout << i.first << " " << i.second << "\n"; 

	return 0;
}