/*
[24/02/19] sechanPark / 1문제
* 출처 : https://softeer.ai/practice/6279

* 번호(파일이름) :  SOFTEER_6279_answer.cpp

* 문제/난이도/시간(커밋 시 첨부) : [SOFTEER] 스마트 물류 / LV.3 / 999분

* 설명 :
	- 
* 풀이 :
	1) 투포인터 알고리즘
	2) 그리디?? 윈도우?? 몰라 호제식 
* 기타 :
	- 백트랙킹으로 풀다가 한 10번 틀림, 입력이 너무 많아서 애초에 안되는 거였음.. 정신차려라 
	- 윈도우 씌워서 멀리있는거 부터 잡자 마인드로 시작했음, 대략 오전 10시부터 
	- 처음에 로봇 기준에서 왼쪽으로 부터 점점 가깝게 확인, 오른쪽으로 부터 점점 가깝게 확인
	
	- 계속 안되서 물품 기준에서 풀어보기도 하고... 왼오왼오왼오 이렇게 하기도 하고.. 
	- 결국은 호제형이 알려줌, 한방향으로 보라고 
	- 그렇다.. 양방향으로 뻗으면 절대 풀수가 없다. 왜냐. 다음 로봇에게서 가장 멀리있는 경우를 내가
	채가는게 맞는건데, 양방향으로 뻗으면 내 오른쪽 로봇 입장에서는 뻇긴걸 수도 있음 
	- 결론은 윈도우 이동방향과 잡는 방향을 동일하게 가져갔어야 했음, 
	- 만약 입력이 더 커지면 투포인터가 더 유리할 수 있겠다는 호 선생의 말.. 
*/
#include <iostream>
#include <vector>
using namespace std; 

vector <char> v; 
vector <bool> vis; 
int N, k; 
int res = 0; 
#define ROBOT 'P'
#define BOX 'H'

void check(int index) {
	int cur = index - k - 1; 

	while (1){
		cur++; 

		if (cur > index + k) {
			return; 
		}

		if (cur < 0 || cur >= N)continue; 
		if (vis[cur] == 0 && v[cur] == ROBOT) {
			vis[cur] = 1; 
			res++; 
			return; 
		}
	}
}

int main() {
	cin >> N >> k; 

	for (int i = 0; i < N; i++) {
		char c; cin >> c; 
		v.push_back(c); 
	}
	vis.assign(N, false); 

	for (int i = 0; i < N; i++) {
		if (v[i] == BOX) {
			check(i); 
		}
	}
	
	cout << res; 
}