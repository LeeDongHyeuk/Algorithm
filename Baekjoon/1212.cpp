#include <iostream>
#include <string>

using namespace std;

string eight[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main() {
	string s;
	cin >> s;

	if (s == "0") {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		int n = s[i] - '0';

		if (i == 0) {
			string two = eight[n];

			if (n == 1) cout << 1;
			else if (n == 2) cout << 10;
			else if (n == 3) cout << 11;
			else cout << eight[n];
		} else {
			cout << eight[n];
		}
	}
}