#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, r;
	string s;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> r >> s;

		for (char ch : s) {
			for (int j = 0; j < r; j++) {
				cout << ch;
			}
		}

		cout << "\n";
	}
}