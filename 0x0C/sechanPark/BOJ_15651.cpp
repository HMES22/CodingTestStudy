/*
[24/02/00] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/15651

* 번호(파일이름) :  BOJ_15651.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] N과 M (3) / 실버 3 / 40분

* 설명 :
	- 중복을 허용하는 순열임 

* 풀이 :
	1) 풀이 생략 
* 기타 :
	- 왜케 헤맨거야 진짜 욕나오네 ㅅ.....ㅂ......
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];

void func(int k) { 
    if (k == m) { 
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' '; 
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) { 
        arr[k] = i; 
        func(k + 1); 
    }
}

int main(void) {
    cin >> n >> m;
    func(0);
}