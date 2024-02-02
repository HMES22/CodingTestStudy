/*
[24/02/02] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/2447

* 번호(파일이름) :  BOJ_2447.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 별 찍기 - 10 / 골드 5 / 20분

* 설명 :
   - 뭐 '종이의 개수' 랑 똑같네.. 더 이상 설명은 없다.
* 풀이 :
   1)
* 기타 :
   -
*/

#include <iostream>
using namespace std;

char board[2200][2200];

void func2(int n, int x, int y) {
   for (int i = x; i < x + n; i++) {
      for (int j = y; j < y + n; j++) {
         board[i][j] = ' ';
      }
   }
   return;
}

void func(int n, int x, int y) {
   //end 
   if (n == 3) {
      for (int i = x; i < x + n; i++) {
         for (int j = y; j < y + n; j++) {
            board[i][j] = '*';
         }
      }
      board[x + 1][y + 1] = ' '; 
      return; 
   }

   //loof
   if (n > 3) {
      int side = n / 3; 

      func(side, x, y); 
      func(side, x, y+ side);
      func(side, x, y + side*2);

      func(side, x + side, y);
      func2(side, x + side, y + side);
      func(side, x + side, y + side * 2);

      func(side, x + side * 2, y);
      func(side, x + side * 2, y + side);
      func(side, x + side * 2, y + side * 2);
   }
}

int main() {
   int cnt; 
   cin >> cnt; 

   func(cnt, 0, 0); 

   for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < cnt; j++) {
         cout << board[i][j];
      }
      cout << "\n";
   }
}