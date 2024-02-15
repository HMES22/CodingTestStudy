/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15654

* 번호(파일이름) :  BOJ_15654.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (5) / 실버 3 / 10분

* 설명 :
	-
* 풀이 :
	1)
* 기타 :
	- 딱 봐도 정렬 그지 같은거 보니깐, STL 쓰라는거 같았음 ㅇㅇ
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m; 
vector <int> v1; 
int main() {
	cin >> n >> m; 
	
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		v1.push_back(x); 
	}

	sort(v1.begin(), v1.end()); 

	do {
		for (int i = 0; i < m; i++) {
			cout << v1[i] << " "; 
		}
		cout << "\n"; 
		reverse(v1.begin() + m, v1.end()); 
	} while (next_permutation(v1.begin(), v1.end())); 
}