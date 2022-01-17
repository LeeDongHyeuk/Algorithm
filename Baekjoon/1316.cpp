#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int cnt = 0;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		bool check = true;

		for (int j = 0; j < str.length() - 1; j++) {
			if (str[j] != str[j + 1]) {
				if (str.find(str[j], j + 2) != string::npos) {
					check = false;
					break;
				}
			}
		}

		if (check) cnt++;
	}

	cout << cnt;
}