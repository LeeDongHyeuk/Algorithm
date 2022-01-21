#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	for (char ch : str) {
		if (ch >= 'a' && ch <= 'm') ch += 13;
		else if (ch >= 'n' && ch <= 'z') ch -= 13;
		else if (ch >= 'A' && ch <= 'M') ch += 13;
		else if (ch >= 'N' && ch <= 'Z') ch -= 13;
		cout << ch;
	}
}