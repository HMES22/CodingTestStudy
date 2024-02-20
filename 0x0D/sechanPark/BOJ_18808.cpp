/*
[24/02/19] sechanPark / 0문제
* 출처 : https://www.acmicpc.net/problem/18808

* 번호(파일이름) :  BOJ_18808.cpp

* 문제/난이도/시간(커밋 시 첨부) : [BOJ] 스티커 붙이기 / 골드 3 / 120분

* 설명 :
    -
* 풀이 :
    1)
* 기타 :
    -
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;

int n, m, s_cnt;
int sti_n, sti_m;

int board[40][40];
int stiker[10][10];

int spin_stiker[10][10];
int spin_n, spin_m;


int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int tflag = 0;

// 0 = 0도 , 1 = 90도, 2 = 180도, 3 = 270도 
void turn_s(int turn) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            spin_stiker[i][j] = 0;
        }
    }

    turn = turn % 4;

    switch (turn) {
    case 0:
        for (int i = 0; i < sti_n; i++) {
            for (int j = 0; j < sti_m; j++) {
                spin_stiker[i][j] = stiker[i][j];
            }
        }
        spin_n = sti_n;
        spin_m = sti_m;
        break;
    case 1:
        for (int i = 0; i < sti_n; i++) {
            for (int j = 0; j < sti_m; j++) {
                spin_stiker[j][sti_n - 1 - i] = stiker[i][j];
            }
        }
        spin_n = sti_m;
        spin_m = sti_n;
        break;
    case 2:
        for (int i = 0; i < sti_n; i++) {
            for (int j = 0; j < sti_m; j++) {
                spin_stiker[sti_n - 1 - i][sti_m - 1 - j] = stiker[i][j];
            }
        }
        spin_n = sti_n;
        spin_m = sti_m;
        break;
    case 3:
        for (int i = 0; i < sti_n; i++) {
            for (int j = 0; j < sti_m; j++) {
                spin_stiker[sti_m - 1 - j][i] = stiker[i][j];
            }
        }
        spin_n = sti_m;
        spin_m = sti_n;
        break;
    default:
        break;
    }
}

void attach() {


    for (int i = 0; i < n; i++) {
        if (spin_n + i > n)continue;
        for (int j = 0; j < m; j++) {
            if (spin_m + j > m)continue;

            int flag = 0;
            for (int i2 = 0; i2 < spin_n; i2++) {
                if (flag)
                    break;
                for (int j2 = 0; j2 < spin_m; j2++) {
                    if (spin_stiker[i2][j2] == 1 && board[i + i2][j + j2] == 1) {
                        flag = 1;
                        break;
                    }
                }
            }

            if (!flag) {
                for (int i3 = 0; i3 < spin_n; i3++) {
                    for (int j3 = 0; j3 < spin_m; j3++) {
                        if (board[i + i3][j + j3] == 0)
                            board[i + i3][j + j3] = spin_stiker[i3][j3];
                    }
                }
                tflag = 1;
                return;
            }
        }
    }
}

int main() {
    cin >> n >> m >> s_cnt;

    for (int i = 0; i < s_cnt; i++) {
        cin >> sti_n >> sti_m;
        for (int i = 0; i < sti_n; i++) {
            for (int j = 0; j < sti_m; j++) {
                cin >> stiker[i][j];
            }
        }
        
        tflag = 0;
        for (int i = 0; i < 4; i++) {
            turn_s(i);
            attach();
            if (tflag == 1)
                break;
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1)
                res++;
        }
    }

    cout << res;
}