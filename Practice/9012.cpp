#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool go(string& s) {
	stack<char> sc;

	for (char c : s) {
		if (c == '(') {
			sc.push(c);
		} else {
			if (sc.empty()) return false;
			sc.pop();
		}
	}
	if (!sc.empty()) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		if (go(s)) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}