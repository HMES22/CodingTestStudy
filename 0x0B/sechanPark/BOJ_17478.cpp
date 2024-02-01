/*
[24/02/01] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/17478

* 번호(파일이름) :  BOJ_17478.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 재귀함수가 뭔가요? / 실버 5 / 30분

* 설명 : 
	- 입력 값 만큼 재귀로 문자 출력.. 문제 참고
* 풀이 :
	1) 앞 재귀, 뒤 재귀 문장으로 해결 EASY함 
* 기타 :
	-
*/

#include <iostream>
#include <string>
using namespace std; 

string s1 = "\"재귀함수가 뭔가요?\"\n"; 
string s2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n"; 
string s3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n"; 
string s4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string s5 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
string s6 = "라고 답변하였지.\n"; 
string dash = "____"; 

void f_dash(int n) {
	for (int i = 0; i < n; i++) {
		cout << dash;
	}
}

void back_word(int n) {
	
	f_dash(n); cout << s6;
	if (n == 0) {
		return;
	}
	return back_word(n - 1); 
}

void front_word(int n) {
	
	if (n == -1) {
		return;
	}
	front_word(n - 1);
	f_dash(n); cout << s1;
	f_dash(n); cout << s2;
	f_dash(n); cout << s3;
	f_dash(n); cout << s4;
	
}

void midle_word(int n) {
	f_dash(n); cout << s1;
	f_dash(n); cout << s5;
	f_dash(n); cout << s6;
}

void func(int n) {
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	
	front_word(n - 1); 
	midle_word(n); 
	back_word(n - 1);

}


int main() {
	int cnt; 
	cin >> cnt; 
	func(cnt); 
}