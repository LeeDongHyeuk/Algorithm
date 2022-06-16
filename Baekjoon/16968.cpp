#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int ans = 1;
	for (int i = 0; i < s.length(); i++) {
		int cnt = s[i] == 'c' ? 26 : 10;
		if (i > 0 && s[i] == s[i - 1]) cnt--;
		ans *= cnt;
	}

	cout << ans << '\n';

	return 0;
}