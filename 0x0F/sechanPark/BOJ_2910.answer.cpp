/*
[24/03/20] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/2910

* 번호(파일이름) :  BOJ_2910.answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 빈도 정렬 / 실버3 / 30분

* 풀이 :
	1) map으로 풀었음
	2) 참고로 map은 알아서 key 기준 자동 sort임, 그리고 iter 잘쓰셈 
	3) 그리고 map은 sort 함수 안먹음, 그래서 vector로 변환해서 해야함 
	4) ㅇㅇ
* 기타 :
	- 솔찍히 짬짬히 봐서 시간을 모르겠긴함 
	- 아니 map 몰라서 찾아볼 수 바꼐....
	- 백터 선언 하면서 할당.. 공부해라 시발 

	- 진심 생각보다 어려움, cmp 함수 만드는거 왜케 햇갈리냐?
	- 그냥 배열을 쭉 늘여놓고, a, b를 본다고 생각하면 됨 
	- 그냥 유지하고 싶으면? t 반환해서 유지한다 마인드?
	- 그래서 먼저 나온 순서면? 그냥 ture 반환해서 유지, 왜? 먼저 나왔으니깐
	- 뭔소리하는지 모르겠긴 한데.. 암튼 그럼.. 그냥 풀었던거 또 풀면 알듯
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std; 
int n; 
int notuse; 

map <int, int> m; 
vector <int> order; 

//1. 빈도 우선 2. 빈도 같으면? 입력 순서 
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second; 
	}
	else { 
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == a.first) {
				return true; 
			}
			else if (order[i] == b.first) {
				return false; 
			}
		}
	}
}

int main() {
	cin >> n >> notuse;
	
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		
		m[x] += 1; 

		bool flag = false; 
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == x) flag = true;
		}
		if (flag == false) {
			order.push_back(x); 
		}
	}
	//이제 빈도 순으로 정렬 떄림 
	vector<pair<int, int>> v(m.begin(), m.end()); 
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second; j++) {
			cout << v[i].first << " "; 
		}
	}
}