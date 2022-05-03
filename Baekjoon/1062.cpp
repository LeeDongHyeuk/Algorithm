#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(int mask, vector<int>& words) {
	int cnt = 0;
	for (int word : words) {
		if ((word & ((1 << 26) - 1 - mask)) == 0) {
			cnt++;
		}
	}
	return cnt;
}

int go(int idx, int k, int mask, vector<int>& words) {
	if (k < 0) return 0;
	if (idx == 26) {
		return count(mask, words);
	}
	int ans = 0;
	int t1 = go(idx + 1, k - 1, mask | (1 << idx), words);
	if (ans < t1) ans = t1;
	if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a') {
		t1 = go(idx + 1, k, mask, words);
		if (ans < t1) ans = t1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> words(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char x : s) {
			words[i] |= (1 << (x - 'a'));
		}
	}

	cout << go(0, k, 0, words) << '\n';

	return 0;
}