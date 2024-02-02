/*
[24/02/02] sechanPark / 1문제
* 출처 : https://www.acmicpc.net/problem/2630

* 번호(파일이름) :  BOJ_2630.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 색종이 만들기 / 실버 2 / 10분

* 설명 :
   - 이 친구는 '종이의 개수'랑 뭐 거의 흡사하다. 참고 
   - 한변의 길이는 최대 128
* 풀이 :
   1) 참고.. 
* 기타 :
   -
*/

#include <iostream>
using namespace std; 

int board[128][128]; 
int res[2]; 


void func(int n, int x, int y) {
   int bef = board[x][y]; 
   int flag = 0; 

   for (int i = x; i < x+n; i++) {
      for (int j = y; j < y+n; j++) {
         int now = board[i][j]; 

         if (now != bef) {
            flag = 1;
            break; 
         }

         bef = now; 
      }
   }

   if (flag == 0) {
      res[bef] += 1;
   }
   else if (flag == 1) {
      int side = n / 2; 

      if (side == 0) {
         return; 
      }

      
      func(side, x, y);
      func(side, x, y + side);
      func(side, x + side, y);
      func(side, x + side, y + side);
   }
}

int main() {
   int cnt; 
   cin >> cnt; 
   for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < cnt; j++) {
         int x; 
         cin >> x; 
         board[i][j] = x; 
      }
   }

   func(cnt, 0, 0); 

   for (int i : res)
      cout << i << "\n"; 
}