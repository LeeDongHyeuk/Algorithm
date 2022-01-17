#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> croatian = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;

	cin >> str;

	for (string s : croatian) {
		while (true) {
			if (str.find(s) == string::npos) break;
			else {
				str.replace(str.find(s), s.length(), "#");
			}
		}
	}

	cout << str.length();
}