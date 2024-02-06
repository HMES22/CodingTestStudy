/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15655

* 번호(파일이름) :  BOJ_15655.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (6) / 실버 3 / 10분

* 설명 :
	-  

* 풀이 :
	1) 풀이 생략 
* 기타 :
	- STL은 신이야 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
vector <int> v1; 
vector <int> v2;
int main(void) {
    cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v1.push_back(x); 
		v2.push_back(1); 
	}
	sort(v1.begin(), v1.end()); 

	for (int i = 0; i < m; i++) {
		v2[i] = 0; 
	}

	do {
		for (int i = 0; i < v2.size(); i++) {
			if (v2[i] == 0) {
				cout << v1[i] << " ";
			}
		}
		cout << "\n"; 
	} while (next_permutation(v2.begin(), v2.end())); 
}