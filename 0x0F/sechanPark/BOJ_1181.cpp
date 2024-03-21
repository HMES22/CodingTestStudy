/*
[24/03/20] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/1181

* 번호(파일이름) :  BOJ_1181.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 단어 정렬 / 실버5 / 10분

* 풀이 :
	1) 그냥 stl 써서 품
* 기타 :
	- 아하 string은 대소문자로 사전 순 정렬 가능하구나~
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std; 
int n; 
vector <string> v; 

bool cmp(string& a, string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size(); 
	}
	else {
		return a < b;
	}
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++){
		string s; 
		cin >> s; 
		v.push_back(s); 
	}

	sort(v.begin(), v.end(), cmp); 

	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i-1] != v[i]) cout << v[i] << "\n";
	}

}