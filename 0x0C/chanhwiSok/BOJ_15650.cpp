//�⺻���� ��Ʈ��ŷ
/*

for������ �������� �������� ũ���� ���� �ȳ�!!(�״�� ���� ����x)

*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		
		return;
	}

	int start = 1;
	if (k != 0)start = arr[k - 1] + 1;

	for (int i = start; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	func(0);
}