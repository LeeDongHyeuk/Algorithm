#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	vector<int> num;
	vector<int> sign;

	sign.push_back(1);
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+') {
				sign.push_back(1);
			} else {
				sign.push_back(-1);
			}
			num.push_back(cur);
			cur = 0;
		} else {
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);

	int ans = 0;
	bool minus = false;
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1) {
			minus = true;
		}
		if (minus) {
			ans -= num[i];
		} else {
			ans += num[i];
		}
	}

	cout << ans << '\n';

	return 0;
}