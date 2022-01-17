#include <iostream>
#include <string>

using namespace std;

int main() {
	int clockArr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
	int total = 0;
	string str;

	cin >> str;

	for (char ch : str) {
		total += clockArr[ch - 'A'];
	}

	cout << total;
}