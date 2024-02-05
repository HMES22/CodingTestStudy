/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15650

* 번호(파일이름) :  BOJ_15650.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (2) / 실버 3 / 15분

* 설명 :
	- STL 사용해서 풀었음
	- 'N과 M (2)'과 비슷해 보이나, 이 친구는 예를 들어 123 이면 
	2 1 이렇게 낮게 빠꾸는 안됨 ㅇㅇ 
	- 무작위 순열은 아니란거임 ㅇㅇ 

* 풀이 :
	1) 풀이 생략 
* 기타 :
	- STL 지린다 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n; 
int m; 
vector <int> v1; 
vector <int> v2;

int main() {
	cin >> n >> m; 
	
	for (int i = 0; i < n; i++) {
		v1.push_back(i+1);
		v2.push_back(1); 
	}

	for (int i = 0; i < m; i++) {
		v2[i] = 0;
	}

	do {
		for (int i = 0; i < v1.size(); i++) {
			if (v2[i] == 0) {
				cout << v1[i] << " ";
			}
		}
		cout << "\n"; 
	} while (next_permutation(v2.begin(), v2.end())); 
}