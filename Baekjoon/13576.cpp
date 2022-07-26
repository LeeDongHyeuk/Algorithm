#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.length();
	auto pi = preprocessing(s);

	vector<int> cnt(n + 1);
	for (int i = 0; i < n; i++) {
		cnt[pi[i]] += 1;
	}
	for (int i = n; i > 0; i--) {
		cnt[pi[i - 1]] += cnt[i];
	}

	vector<pair<int, int>> ans;
	for (int i = n; i > 0; i = pi[i - 1]) {
		ans.push_back(make_pair(i, cnt[i] + 1));
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';

	for (auto& p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}