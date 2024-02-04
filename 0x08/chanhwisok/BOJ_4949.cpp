#include <bits/stdc++.h>
using namespace std;

/*
0. 스택 만들기, getline 한게 "." 이면 멈춤, 
1. ( 나 [ 가 오면 push
2. ]나 ( 가 오면
	2-1. ( + ) 이거나 [ + ] 이면 no
	2-2. ( + ] 이거나   [ + ) 이면 no
	2-3. top이 ), ] 이면 pop
3. 마지막 순간에 스택이 비어있으면 yes, 아니라면 no
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