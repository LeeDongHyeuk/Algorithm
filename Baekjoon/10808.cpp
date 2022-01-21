#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;

	for (char i = 'a'; i <= 'z'; i++) {
		cout << count(s.begin(), s.end(), i) << " ";
	}
}


/*
* 내가 한 풀이
* 
int main() {
	string s;
	cin >> s;

	vector<int> alphabet(26);

	for (char ch : s) {
		alphabet[ch - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
}
*/