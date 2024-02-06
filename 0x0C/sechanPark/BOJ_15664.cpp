/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15664

* 번호(파일이름) :  BOJ_15664.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (10) / 실버 2 / 60분?

* 설명 :
	-  

* 풀이 :
	1) 그냥 중복 되는거 벡터에 떄려넣고 맞는지 다 확인해봄, 좀 아닌거 같긴함.. 
* 기타 :
	- STL안쓰고 풀어봤음 
	- 개판으로 짜긴 했는데 맞는건가? 잘 모르겠네.... 
	- 수업 시간 내내 조금씩 봐가지고.. 얼마 걸렸는지 모르겠음 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m; 
int flag = 0; 
vector <int> v1; 
vector <int> arr; 
vector <vector<int>> v2; 
bool vis[8]; 

void func(int depth) {
	if (depth == m) {

		if (!v2.empty()) {
			for (int i = 0; i < v2.size(); i++) {
				int buf = 0; 
				for (int j = 0; j < m; j++) {
					if (v2[i][j] == arr[j])
						buf++; 
				}
				if (buf == m) {
					return; 
				}
			}
		}
		
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		v2.push_back(arr);
		return; 
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (depth > 0) {
				if (arr[depth - 1] > v1[i])continue; 
			}

			vis[i] = 1;
			arr[depth] = v1[i];
			func(depth + 1);
			vis[i] = 0; 
		}
	}
}

int main(void) {
    cin >> n >> m;
    
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v1.push_back(x); 
	}
	sort(v1.begin(), v1.end()); 
	arr.assign(m, 0); 

	func(0); 
}