#include <iostream>
#include <vector>

using namespace std;

int player[20][20];
int n;

int go(int idx, vector<int>& first, vector<int>& second) {
	if (idx == n) {
		if (first.size() != n / 2) return -1;
		if (second.size() != n / 2) return -1;

		int t1 = 0;
		int t2 = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				t1 += player[first[i]][first[j]];
				t2 += player[second[i]][second[j]];
			}
		}
		int diff = abs(t1 - t2);
		return diff;
	}
	int ans = -1;
	first.push_back(idx);
	int t1 = go(idx + 1, first, second);
	if (ans == -1 || (t1 != -1 && ans > t1)) {
		ans = t1;
	}
	first.pop_back();
	second.push_back(idx);
	int t2 = go(idx + 1, first, second);
	if (ans == -1 || (t2 != -1 && ans > t2)) {
		ans = t2;
	}
	second.pop_back();

	return ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> player[i][j];
		}
	}

	vector<int> first, second;
	cout << go(0, first, second) << '\n';

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int player[20][20];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> player[i][j];
		}
		if (i < n / 2) c[i] = 0;
		else c[i] = 1;
	}

	int ans = 10000001;

	do {
		int t1 = 0;
		int t2 = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (c[i] == 0 && c[j] == 0) t1 += player[i][j];
				else if (c[i] == 1 && c[j] == 1) t2 += player[i][j];
			}
		}
		if (abs(t1 - t2) < ans) ans = abs(t1 - t2);
	} while (next_permutation(c.begin(), c.end()));

	cout << ans << '\n';

	return 0;
}
*/