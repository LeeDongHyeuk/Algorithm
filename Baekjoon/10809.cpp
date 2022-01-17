#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	for (char ch = 'a'; ch <= 'z'; ch++) {
		int n = str.find(ch) == string::npos ? -1 : str.find(ch);
		cout << n << " ";
	}
}