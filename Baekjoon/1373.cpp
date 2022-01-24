#include <iostream>
#include <string>

using namespace std;

int main() {
	string two;
	cin >> two;

	int size = two.length();

	if (size % 3 == 1) {
		cout << (two[0] - '0');
	} else if (size % 3 == 2) {
		cout << (two[0] - '0') * 2 + (two[1] - '0');
	}

	for (int i = size % 3; i < size; i += 3) {
		cout << (two[i] - '0') * 4 + (two[i + 1] - '0') * 2 + (two[i + 2] - '0');
	}
}