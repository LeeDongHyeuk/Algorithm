#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int reverseInt(string str) {
	reverse(str.begin(), str.end());
	return stoi(str);
}

int main() {
	string a, b;

	cin >> a >> b;

	int big = reverseInt(a) >= reverseInt(b) ? reverseInt(a) : reverseInt(b);

	cout << big;
}