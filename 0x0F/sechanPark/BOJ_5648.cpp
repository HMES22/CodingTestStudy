/*
[24/03/20] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/5648

* 번호(파일이름) :  BOJ_5648.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 역원소 정렬 / 실버5 / 10분

* 풀이 :
	1) 그냥 stl 써서 품
* 기타 :
	- 입력 값 커서 런타임 터졌었음 잘 봐라 문제좀 
	- (int형 최댓값 2.1*10^9<10^12<long long int 최댓값 9.22*10^18)
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std; 
int n; 
vector <long long> v; 
int main() {
	cin >> n; 
	while (n--){
		string s; 
		cin >> s; 

		reverse(s.begin(), s.end());
		long long a = stoll(s);

		
		v.push_back(a); 
	}

	sort(v.begin(), v.end()); 

	for (auto i : v) {
		cout << i << "\n"; 
	}
}