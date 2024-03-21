/*
[24/03/19] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/1431

* 번호(파일이름) :  BOJ_1431.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 시리얼 번호 / 실버3 / 30분 

* 설명 :
	- 그냥 sort에 조건 넣기 
* 풀이 :
	1) 그냥 문제 그대로 구현 
* 기타 :
	- string은 대소 비교 가능하구나~
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

vector <string> v; 
int cnt; 

bool cmp(string& a, string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size(); 
	}
	else {
		int bufa = 0;
		int bufb = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') {
				bufa += a[i] - '0';
			}
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] >= '0' && b[i] <= '9') {
				bufb += b[i] - '0';
			}
		}

		if (bufa != bufb) {
			return bufa < bufb; 
		}
		else {
			return a < b;
		}
	}
}

int main() {
	cin >> cnt; 
	for (int i = 0; i < cnt; i++) {
		string s; 
		cin >> s; 
		v.push_back(s); 
	}

	sort(v.begin(), v.end(), cmp); 

	for (auto i : v) {
		cout << i << "\n"; 
	}
}
