#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		string str;
		bool check = false;
		getline(cin, str);

		stack<char> s;
		
		if (str == ".") break;

		for (char ch : str) {
			if (ch == '(' || ch == '[') {
				s.push(ch);
			} else if (ch == ')') {
				if (s.empty() || s.top() != '(') {
					check = true;
					break;
				}
				s.pop();
			}  else if (ch == ']') {
				if (s.empty() || s.top() != '[') {
					check = true;
					break;
				}
				s.pop();
			}
		}

		if (check || !s.empty()) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}