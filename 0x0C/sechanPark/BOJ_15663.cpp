/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15663

* 번호(파일이름) :  BOJ_15663.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (9) / 실버 2 / 10분

* 설명 :
	-  

* 풀이 :
	1) 풀이 생략 
* 기타 :
	- STL은 신이야 
	- 솔찍히 그냥 왜 맞는지 모르겠음, 그냥 풀었는데 맞았음... 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
vector <int> v1; 

int main(void) {
    cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v1.push_back(x); 
	}
	
	sort(v1.begin(), v1.end()); 

	do {
		for (int i = 0 ; i < m; i++) {
			cout << v1[i] << " "; 
		}
		cout << "\n"; 
		reverse(v1.begin() + m, v1.end()); 
	} while (next_permutation(v1.begin(), v1.end())); 
}