/*
[24/02/02] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/1992

* 번호(파일이름) :  BOJ_1992.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 쿼드트리 / 실버 1 / 10분

* 설명 :
   - 뭐 '종이의 개수' 랑 똑같네.. 더 이상 설명은 없다.
* 풀이 :
   1)
* 기타 :
   -
*/

#include <iostream>
using namespace std;

char board[64][64]; 

void func(int n, int x, int y) {
   char bef = board[x][y]; 
   int flag = 0; 

   for (int i = x; i < x+n; i++) {
      for (int j = y; j < y+n; j++) {
         char now = board[i][j]; 

         if (now != bef) {
            flag = 1;
            break; 
         }

         bef = now; 
      }
   }

   if (flag) {
      int side = n / 2; 
      if (n == 0) {
         return; 
      }
      cout << "(";
      func(side, x, y); 
      func(side, x, y + side);
      func(side, x + side, y);
      func(side, x + side, y + side);
      cout << ")";
   }
   else {
      cout << bef; 
   }

   
}

int main() {
   int cnt; 
   cin >> cnt; 

   for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < cnt; j++) {
         char c; 
         cin >> c; 
         board[i][j] = c; 
      }
   }

   func(cnt, 0, 0); 
}