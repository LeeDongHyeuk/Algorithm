#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	char maxValue;
	int maxCnt = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		int cnt = 0;

		for (char c : str) {
			if (c == ch) cnt++;
		}

		if (cnt > maxCnt) {
			maxCnt = cnt;
			maxValue = ch;
		} else if (cnt == maxCnt) {
			maxValue = '?';
		}
	}

	cout << maxValue;
}