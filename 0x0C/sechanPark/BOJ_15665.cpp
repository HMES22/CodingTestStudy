/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15665

* 번호(파일이름) :  BOJ_15665.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (11) / 실버 2 / 40분

* 설명 :
	-  

* 풀이 :
	1) 사실 어케 푼지 모르겠음, 고스트 바둑왕 느낌임
	2) 중복 가능이라서 그냥 전체 다 받아서 정렬하고 
	3) 정렬하면 중복 되는게 앞뒤로 나타나니깐, 이전 값 비교해서 배열 하나 다시 짬 
	4) 줄어든 배열 만큼 돌려서 그냥 중복 순열 출력함 
	5) 근데 모르겠음 쩃든 품 
* 기타 :
	- N과 M (10)이랑 비슷하게 풀었더니 시간초과 나서 해맴 
	- 아까 그거 답지보고 다시 풀어야할듯 ㄹㅇ
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
vector <int> v1; 
vector <int> arr; 
vector <int> v2; 

void func(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return; 
	}

	for (int i = 0; i < n; i++) {
		arr[depth] = v2[i];
		func(depth + 1);
	}
}

int main(void) {
    cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v1.push_back(x); 
	}
	sort(v1.begin(), v1.end()); 

	int buf = 0; 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (buf == v1[i]) { 
			cnt++;
			buf = v1[i];
			continue; 
		}
		v2.push_back(v1[i]);
		buf = v1[i]; 
	}

	n -= cnt; 
	arr.assign(m, 0); 

	func(0); 
}