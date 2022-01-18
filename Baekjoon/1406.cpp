#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int m;

	cin >> str >> m;

	stack<char> left, right;

	for (char ch : str) {
		left.push(ch);
	}

	while (m--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		} else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		} else if (cmd == 'B') {
			if (!left.empty()) left.pop();
		} else if (cmd == 'P') {
			char x;
			cin >> x;

			left.push(x);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}


	return 0;
}