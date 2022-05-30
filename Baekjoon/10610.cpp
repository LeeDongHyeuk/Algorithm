#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int sum = 0;
	bool flag = false;
	for (char c : s) {
		sum += (c - '0');
		if (c - '0' == 0) flag = true;
	}

	if (sum % 3 == 0 && flag) {
		sort(s.begin(), s.end(), [](char a, char b) {
			return a > b;
		});
		cout << s << '\n';
	} else {
		cout << -1 << '\n';
	}

	return 0;
}