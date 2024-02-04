#include <bits/stdc++.h>
using namespace std;

/*
0. ���� �����, getline �Ѱ� "." �̸� ����, 
1. ( �� [ �� ���� push
2. ]�� ( �� ����
	2-1. ( + ) �̰ų� [ + ] �̸� no
	2-2. ( + ] �̰ų�   [ + ) �̸� no
	2-3. top�� ), ] �̸� pop
3. ������ ������ ������ ��������� yes, �ƴ϶�� no
*/


int main() {
	freopen("0x08_ex.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	

	while (true) {
		stack<char>s;
		string a;
		getline(cin, a);
		if (a == ".") break;
		bool isValue = true;
		for (auto c : a) {
			if (c == '(' || c == '[') s.push(c);

			else if (c == ')') {
				//s.top() == '['
				if (s.empty() || s.top() != '(' ) {
					isValue = false;
					break;
				}
				s.pop();
			}

			else if (c == ']' ) {
				if (s.empty() || s.top() != '[' ) {
					isValue = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty()) isValue = false;
		else isValue = true;

		if (isValue) cout << "yes" << "\n";
		else cout << "no" << "\n";
		
	}
}