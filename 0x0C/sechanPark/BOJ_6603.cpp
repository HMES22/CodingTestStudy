/*
[24/02/06] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/6603

* 번호(파일이름) :  BOJ_6603.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 로또 / 실버 2 / 30분

* 설명 :
	-  독일 로또는 1~49 수 중에서 6개를 뽑는다 
	- 6개 보다 더 많이 골라서 만든 조합에서 6개를 뽑는게 전략이래

* 풀이 :
	1) 그냥 하던거 연장이라서 별 감흥없음
* 기타 :
	- 뭔가 그 순열이랑 조합이랑 차이가 
	- 순열은 오름차 내림차 생각 안하고 나오는거고 
	- 조합은 오름차로만 나옴
	- stl 기준에서 ㅇㅇ 
	- 그냥 햇갈려서, stl로 풀어보고, 안되면 재귀 함수 만들어서 하는듯
	- 그니깐 잘 몰라서 걍 경우의 수 다 때려서 출력보고 수정하는듯.. 에바임 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int test = 0; 

	while (1){
		cin >> test; 
		if (test == 0) {
			break; 
		}
		//start//
		vector<int> v1; 
		vector<int> v2;
		
		for (int i = 0; i < test; i++) {
			int x; cin >> x; 
			v1.push_back(x); 
			v2.push_back(1); 
		}
		
		for (int i = 0; i < 6; i++) {
			v2[i] = 0; 
		}

		do {
			for (int i = 0; i < test; i++) {
				if(v2[i] == 0)
					cout << v1[i] << " "; 
			}
			cout << "\n"; 
		} while (next_permutation(v2.begin(), v2.end())); 
		cout << "\n";
	}
}