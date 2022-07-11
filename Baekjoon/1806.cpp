#include <iostream>

using namespace std;

int a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = n + 1;

	while (left <= right && right < n) {
		if (sum < s) {
			right++;
			sum += a[right];
		} else if (sum == s) {
			if (right - left + 1 < ans) {
				ans = right - left + 1;
			}
			right++;
			sum += a[right];
		} else if (sum > s) {
			if (right - left + 1 < ans) {
				ans = right - left + 1;
			}
			sum -= a[left];
			left++;
		}
	}
	if (ans > n) ans = 0;

	cout << ans << '\n';

	return 0;
}