/*
��ŷ�� BFS �⺻ ����
BFS ó�� ����� �ܿ�� �� ���� �ȵ�.. �ᱹ �׳� ����ħ.


���� �κ� : �����ƴµ��� ��ȳ��ͼ� �̸����� ���ٰ� �˾� ���� .. 
!!!!!��ũ�� ��� �ÿ� �����ݷ� ���� �ȵ�!!!!!

���� �ٽ� : BFS �⺻ ���Ŀ��� ���� Ŀ�ٶ� �κа� �̾��� �͵��� ���� ī��Ʈ �ϴ� �� �߰�..

�̾��� �͵��� ���� = ������ 

���� Ŀ�ٶ� �κ�(������ ����) = POP �ϸ鼭 ī��Ʈ

�Ⱥ��� �ٽ� Ǯ���...
*/

#include <bits/stdc++.h>
using namespace std;
#define X first               //��ũ�� ���ÿ� �����ݷ� ��������!!!
#define Y second			//�׳� ���󾲱⸸ �ߴµ� �ȵǼ� ������ԤФ�

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[502][502];
int vis[502][502];


int main() {
	freopen("input.txt", "r", stdin);


	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int num = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {  //(i,j)�� ���������� �ϰ� ����.
			if (board[i][j] == 0 || vis[i][j]) continue;

			num++; // ���ذ� �� �ȉ�� �κ� �� ���⼭ �׸� �߰�??
			//==> �������� ���ϴ� �κ��̰� ������ �������� ��, �׸��ϳ��� ����� �����ϸ� ��!
			//==> ���� if �������� ����, �̾��� �κ��� �ȵ�

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0;

			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;

					vis[nx][ny] = 1;

					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area);
		}
		
	}
	cout << num << '\n' << mx;


}
