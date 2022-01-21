#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	while (getline(cin, str)) {
		int lower = 0;
		int upper = 0;
		int number = 0;
		int space = 0;

		for (char ch : str) {
			if (ch >= 'a' && ch <= 'z') lower++;
			else if (ch >= 'A' && ch <= 'Z') upper++;
			else if (ch >= '0' && ch <= '9') number++;
			else if (ch == ' ') space++;
		}

		cout << lower << " " << upper << " " << number << " " << space << "\n";
	}
}