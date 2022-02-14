#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[10][10];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> c(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		c[i] = i;
	}

	int ans = 10000001;
	do {
		if (c[0] != 0) break;
		int sum = 0;
		bool check = true;
		for (int i = 1; i < n; i++) {
			if (a[c[i - 1]][c[i]] == 0) check = false;
			else sum += a[c[i - 1]][c[i]];
		}
		if (check && a[c[n - 1]][c[0]] != 0) {
			sum += a[c[n - 1]][c[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(c.begin(), c.end()));

	cout << ans << '\n';
	return 0;
}