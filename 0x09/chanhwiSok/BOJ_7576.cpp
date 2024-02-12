/*
�������� 2���̻��̶��??
=> �ʱ��� ������ Q�� ������ ������ �ȴ�!!

��� �Է°� m,n �Ųٷ� ���ִ� ������ ������ �����ϱ�!!
=> �̰Ŷ����� ���� ���.

*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[1002][1002];
int vis[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int day;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> m >> n;

	queue<pair<int, int>> Q;


	//������ Q
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {  //�������
				Q.push({ i,j });
			}
			if (board[i][j] == 0) { //0�̶�� �ϴ� ����������
				vis[i][j] = -1;// '����' ���� �ʾ����� -1(�ð�)
			}
		}
	}

	


	while (!Q.empty()) {


		pair<int, int>cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] >= 0) continue; //�丶�䰡 ������

			vis[nx][ny] = vis[cur.X][cur.Y] + 1; //day�� ��
			Q.push({nx,ny});

		}
	}

	//vis Ȯ�� �� ��� �ܰ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == -1) {
				cout << -1;
				return 0;
			}
			day = max(day, vis[i][j]); //vis�� �ִ밪 = ��¥
		}
	}

	cout << day;
	
}