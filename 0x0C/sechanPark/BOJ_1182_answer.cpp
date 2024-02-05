/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/1182

* 번호(파일이름) :  BOJ_1182_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 부분수열의 합 / 실버 2 / 30분

* 설명 : 
	- 정수의 개수 / 수열의 원소의 합을 입력
	- 정수 개수 만큼의 정수 입력 
	- 수열 원소의 합과 같은 수열의 개수를 출력하라 
* 풀이 :
	1) 백트랙킹이다. 
	2) 재귀를 사용한다. 
* 기타 :
	- 기초문제라서 보고 풀었음~
	- 사실 상 'N과 M(1)'이랑 같은 문제라고 봐도 될듯, 구조는 완전 똑같음  
	- 근데 답 안보고 풀었으니깐 사실상 내가 푼거임 ㅇㅈ? 
	- 아나 계속 틀려서 뭔가 했더니, 양수 부분 수열만 쓰는거라 공집합 제외네 에헤이~
*/

#include <iostream>
using namespace std; 

int n; 
int total_sum; 
long long arr[20];
long long res; 

void func(int cnt, long long buf, int i) {
	
	if (cnt == n) {
		//cout << buf << "\n"; 
		if (buf == total_sum)
			res++; 

		return; 
	}

	
	func(cnt + 1, buf + 0, i+1); 
	func(cnt + 1, buf + arr[i], i+1);
	
}
int main() {
	cin >> n >> total_sum;
	for (int i = 0; i < n; i++) {
		long long x; 
		cin >> x;
		arr[i] = x; 
	}

	func(0, 0, 0); 
	if (total_sum == 0)
		res -= 1;
	cout << res; 
}

/////////////////////////////////////////////////////

/*
[24/02/00] sechanPark / 0문제
* 출처 :

* 번호(파일이름) :  BOJ_번호_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : 번외

* 설명 :
	- STL 사용해서 풀었음
* 풀이 :
	1) STL 이 친구를 이용하여 중복없이 원하는 숫자만큼 뽑는거임
	2) 설명이 안됨... 걍 보고 이해하세요
* 기타 :
	- 어째 이렇게 푸는게 더 어려운거 같기도 하고..
	- 메모리 소모는 똑같은데, 시간은 압도적으로 줄었음 
	- 코드 길이도 적어지고.. 나쁘지 않은듯? 
	- 근데 이거 비교용? 0101 이 벡터 친구도 오름차로 해놔야됨 잊지말게나
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n; 
int sum; 
int res; 

vector <int> v1; 
vector <int> v2; 

int main() {
	cin >> n >> sum;

	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x; 
		v1.push_back(x); 
		v2.push_back(0); 
	}

	for (int i = 0; i < n; i++) {
		v2[n - (i + 1)] = 1; 

		do {
			int buf = 0;
			for (int i = 0; i < v2.size(); i++) {
				if (v2[i] == 1) {
					buf += v1[i]; 
				}
			}
			
			if (buf == sum) {
				res++; 
			}
		} while (next_permutation(v2.begin(), v2.end()));
	}

	cout << res; 
}