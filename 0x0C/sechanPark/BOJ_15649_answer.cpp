/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15649

* 번호(파일이름) :  BOJ_15649_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (1) / 실버 3 / 30분

* 설명 : 
	- 자연수 n과 m이 주어지는데, 1~n까지 자연수 중에서 중복 없이 m개 고른
	- 수열을 출력 , 사전 순으로... 
* 풀이 :
	1) 백트랙킹이다. 
	2) 재귀를 사용한다. 
	3) 수열을 만드는데 사용한 수는 쓰지 않는다. 
* 기타 :
	- 기초문제라서 보고 풀었음~ 
	- 보고 풀어도 모르겠씀...
*/

#include <iostream>
using namespace std; 

int arr[10]; 
bool vis[10]; 
int n, m; 

void func(int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n"; 
		return; 
	}

	for (int i = 1; i <= n; i++) {
		
		if (vis[i] == 0) {
			vis[i] = 1; 
			arr[cnt] = i;
			func(cnt + 1); 
			vis[i] = 0; 
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n >> m;
	func(0); 
}

/////////////////////////////////////////////////////////////////

/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15649 / https://flowersayo.tistory.com/83

* 번호(파일이름) :  BOJ_15649.cpp

* 문제/난이도/시간(커밋 시 첨부) : 번외

* 설명 :
	- 바킹독에서 풀었던 문제를 STL 활용하여 풀어보자 
* 풀이 :
	1) next_permutation을 활용하면 nPn의 순열을 생성 가능하다
	2) 하지만 nPr의 순열을 뽑아내려면(전체 대해서 아니라, 특정 길이만 짜르기)
	중복 순열이 발생하기 때문에 다른 방법이 필요..
	3)순열 구할 때마다 내가 원하는 자리수 이외를 reverse 해버리면 됨
	4) 그러면 가장 큰 순열의 경우의수? 가 나와서 중복 순열 무시 가능 
* 기타 :
	- 해당 stl은 오름차 순에 반응한다는 걸 명심 
	- 내림 차에 반응하는 stl도 존재함 ㅇㅇ
	- cf) 이건 뭐 모르면 못 풀겠노...
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n; 
int m; 

vector <int> v1; 

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		v1.push_back(i); 
	}

	do {
		for (int i = 0; i < m; i++) {
			cout << v1[i] << " ";
		}
		cout << "\n"; 
		reverse(v1.begin() + m, v1.end()); 
	} while (next_permutation(v1.begin(), v1.end())); 
}