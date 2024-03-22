/*
[24/03/22] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/1463

* 번호(파일이름) :  BOJ_1463_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 1로 만들기 / 실버3 / 30분

* 풀이 :
	1) 바킹독 예제
* 기타 :
	- 어렵당...  
*/

#include <iostream>
using namespace std; 
int n; 
int num[1000005]; 
int main(){
	cin >> n; 
	num[1] = 0; //숫자 1은, 연산 횟수 0회 
	for(int i = 2; i <= n; i++){
		num[i] = num[i-1] + 1; //1더하면 1회 올라가겠징?
		if(i % 2 == 0) num[i] = min(num[i], num[i/2] + 1); 
		if(i % 3 == 0) num[i] = min(num[i], num[i/3] + 1); 
	}
	cout << num[n]; 
}