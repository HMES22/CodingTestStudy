#include<bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (!isused[i] && tmp!=num[i]) {
			arr[k] = num[i];
			tmp = arr[k];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	sort(num, num + n);

	func(0);

}