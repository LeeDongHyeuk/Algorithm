#include <iostream>
#include <vector>

using namespace std;

bool check(vector<long long>& a, long long mid, long long m) {
	int n = a.size();
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - mid > 0) {
			cnt += a[i] - mid;
		}
	}
	return cnt >= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long m;
	cin >> n >> m;

	vector<long long> a(n);
	long long l = 0;
	long long r = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (r < a[i]) r = a[i];
	}

	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(a, mid, m)) {
			if (mid > ans) ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << ans << '\n';

	return 0;
}