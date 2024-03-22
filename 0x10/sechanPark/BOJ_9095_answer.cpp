/*
[24/03/22] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/9095

* 번호(파일이름) :  BOJ_9095_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 1, 2, 3 더하기 / 실버3 / 30분

* 풀이 :
	1) 테이블 : 1, 2, 3의 합으로 나타내는 방법의 수 
	2) 점화식(규칙) : 앞의 3가지의 방법의 수로 방법의수 정해짐, 약간 피보나치 느꺰 
	3) 초기값 : d[1] = 1 , d[2] = 2, d[3] = 4
* 기타 :
	- 어렵당...  
*/

#include <iostream>
using namespace std;
int test; 
int n; 
int d[11]; 
int main(){
	cin >> test; 

	d[1] = 1; d[2] = 2; d[3] = 4; 
	for(int i = 4; i < 11; i++){
		d[i] = d[i-1] + d[i-2] + d[i-3]; 
	}
	
	while(test--){
		cin >> n; 
		cout << d[n] << "\n"; 
	}
}