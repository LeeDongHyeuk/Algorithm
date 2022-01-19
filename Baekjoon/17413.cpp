#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	bool flag = false;
	stack<char> str;

	s += " ";

	for (char ch : s) {
		if (ch == '<' || ch == ' ') {
			if (ch == '<') flag = true;

			while (!str.empty()) {
				cout << str.top();
				str.pop();
			}
			cout << ch;
		} else if (ch == '>') {
			cout << ch;
			flag = false;
		} else if (flag) {
			cout << ch;
		} else {
			str.push(ch);
		}
	}
}