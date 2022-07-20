#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
int mod = 127;
int base = 256;

int h(string s) {
	int ans = 0;
	for (char ch : s) {
		ans = (ans * base + ch) % mod;
	}
	return ans;
}

int match(string& s, string& p) {
	int n = s.length();
	int m = p.length();
	if (n < m) return 0;

	int hash_p = h(p);
	int hash_s = h(s.substr(0, m));
	int first = 1;
	for (int i = 0; i < m - 1; i++) {
		first = (first * base) % mod;
	}

	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) {
			if (s.substr(i, m) == p) return 1;
		}

		if (i + m < n) {
			hash_s = hash_s - (s[i] * first) % mod;
			hash_s = (hash_s + mod) % mod;
			hash_s = ((hash_s * base) % mod + s[i + m]) % mod;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, p;
	cin >> s >> p;
	cout << match(s, p) << '\n';

	return 0;
}
*/

vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		} else {
			pi[i] = 0;
		}
	}

	return pi;
}

vector<int> kmp(string s, string p) {
	auto pi = preprocessing(p);
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int i = 0;
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			} else {
				j += 1;
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, p;
	cin >> s >> p;
	auto matched = kmp(s, p);
	if (matched.size() > 0) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}

	return 0;
}