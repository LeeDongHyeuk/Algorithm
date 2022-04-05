#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int alpha[26];
vector<int> num;
vector<char> letters;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (char c : s[i]) {
			letters.push_back(c);
		}
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	int m = letters.size();

	for (int i = 9; i > 9 - m; i--) {
		num.push_back(i);
	}

	int ans = 0;
	do {
		int sum = 0;

		for (int i = 0; i < m; i++) {
			alpha[letters[i] - 'A'] = num[i];
		}

		for (string str : s) {
			int now = 0;
			for (char c : str) {
				now = now * 10 + alpha[c - 'A'];
			}
			sum += now;
		}

		if (sum > ans) ans = sum;
	} while (prev_permutation(num.begin(), num.end()));

	cout << ans << '\n';
	return 0;
}