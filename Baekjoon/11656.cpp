#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<string> strs(s.size());

	for (int i = 0; i < s.size(); i++) {
		strs[i] = s.substr(i);
	}

	sort(strs.begin(), strs.end());

	for (int i = 0; i < s.size(); i++) {
		cout << strs[i] << "\n";
	}
}
