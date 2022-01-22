#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> s;

	for (char ch : str) {
		if (ch == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		} else if (ch == '(') {
			s.push(ch);
		} else if (ch == '+' || ch == '-') {
			while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(ch);
		} else if (ch == '*' || ch == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(ch);
		} else {
			cout << ch;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}