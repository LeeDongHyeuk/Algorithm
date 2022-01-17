#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int cnt = 1;

	getline(cin, str);

	for (char ch : str) {
		if (ch == ' ') cnt++;
	}

	if (str[0] == ' ') cnt--;
	if (str[str.size() - 1] == ' ') cnt--;

	cout << cnt;
}