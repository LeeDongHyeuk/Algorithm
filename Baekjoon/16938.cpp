#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, r, x;
	cin >> n >> l >> r >> x;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		int sum = 0;
		int high = 0;
		int low = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cnt++;
				sum += a[j];
				if (high == 0 || high < a[j]) high = a[j];
				if (low == 0 || low > a[j]) low = a[j];
			}
		}

		if (cnt >= 2 && sum >= l && sum <= r && high - low >= x) ans++;
	}

	cout << ans << '\n';

	return 0;
}