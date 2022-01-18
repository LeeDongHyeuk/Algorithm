#include <iostream>
#include <string>

using namespace std;

string valid(string str) {
	int cnt = 0;

	for (char ch : str) {
		if (ch == '(') {
			cnt++;
		} else {
			cnt--;
			if (cnt < 0) return "NO";
		}
	}

	return cnt == 0 ? "YES" : "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		cout << valid(str) << "\n";
	}

	return 0;
}