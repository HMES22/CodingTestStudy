//�ʱ� ������ ��°� ���ȿͼ� ��ǰ

/* �߻����

<�ʿ��� �Լ�>
1. ��� ���� ���� ������ ĥ�������� Ȯ���ϴ� �Լ�
2. ���� Ȯ���ϰ�, �ʿ��� ��� 4����Ͽ� ����ϴ� �Լ�.

<1�� �Լ�>
��ȸ �ϰ� �ٸ��� ������ false ��ȯ. false�� �� ��� ����.
true ��� �������� ����.

<2�� �Լ�>
1���Լ��� ȣ���ϰ� �˻�.
�ٸ���� '�ڸ���', ��� ȣ��

<main>
�ʹ� �� ������ ���� func

*/


#include<bits/stdc++.h>
using namespace std;
int n;

int board[130][130];
int ans[2];

bool check(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++)
			//1. ���簪�� �ʱⰪ�� ��
			//�ٸ��ٸ� false => �ٽ� ���
		{
			if (board[i][j] != board[x][y]) return false;
		}
	
	}
	return true;
}

void func(int n, int x, int y) {
	if (check(n, x, y)) {		
		ans[board[x][y]]++; 
		return; //check �Լ� ���� true�̸� ���� ������ �߰��� ����
				//���ÿ� ���� ��Ȱ
	}
	//false�̸� �ڸ��� �ٽ� ���� ����
	for (int i = 0; i < 2; i++) //�׿������� ������(�ڸ���)
		for (int j = 0; j < 2; j++) 
			func(n / 2, x + i * n / 2, y + j * n / 2);
			//������ 4���� �����, �� �Լ� ����.
}


int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	func(n, 0, 0); //ù ����. 

	for (int i = 0; i < 2; i++) cout << ans[i] << '\n';

}

