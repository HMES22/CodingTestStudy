/*
[24/03/21] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/7795

* 번호(파일이름) :  BOJ_7795_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 먹을 것인가 먹힐 것인가 / 실버3 / 30분

* 풀이 :
	1) 사실 완탐말고 정렬의 장점이 뭘까 궁금해서 봄
	2) 크게 다른 느낌은 없긴 한데, 그냥 탐색양을 줄일 수 있는게 장점임, 쩃든 조건 들어간 완탐임 ㅇㅇ 쌉효율적은 아님 
	3) 왜 나는 이런 시각이 없지? 진짜 부셔버리고 싶네
* 기타 :
	-
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int test; 
int n;
int m; 

vector<int>a;
vector<int>b;
int res; 

int main() {
	cin >> test; 
	while (test--){
		cin >> n >> m; 
		a = vector<int>(n, 0); 
		b = vector<int>(m, 0);

		for (int i = 0; i < n; i++) {	
			cin >> a[i]; 
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i]; 
		}

		sort(a.begin(), a.end()); 
		sort(b.begin(), b.end()); 

		res = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) res++;
				else break; 
			}
		}
		cout << res << "\n"; 
	}
}