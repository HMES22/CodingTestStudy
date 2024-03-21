/*
[24/03/19] sechanPark / 2문제
* 출처 : https://www.acmicpc.net/problem/11652

* 번호(파일이름) :  BOJ_11652_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 카드 / 실버4 / 30분 

* 설명 :
	- 숫자 배열에 넣어서 샐려고 했는데, 수가 어마어마하게 큼 
	- 그래서 정렬을 활용하여 푼다 
* 풀이 :
	1) 정렬 
	2) 그리고 알아서 ㅇㅇ 
* 기타 :
	- 뭐 그냥 보고 푼거라서...
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
using ll = long long; 

vector <ll> v; 
int n; 

ll cnt = 0; 
ll max_cnt = 0; 
ll res = -((ll)1 << 62)-1; 

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		ll x; 
		cin >> x; 
		v.push_back(x); 
	}

	sort(v.begin(), v.end()); 

	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i - 1] == v[i]) cnt++; //앞뒤 같으면 하나씩 셈 
		else { //다르면? 
			if (cnt > max_cnt) {
				max_cnt = cnt; 
				res = v[i-1]; 
			}
			cnt = 1; 
		}
	}
	//마지막은 주욱 나오니깐 처리가 안됨 ㅇㅇ 
	if (cnt > max_cnt) res = v[n - 1]; 
	
	cout << res; 
}
