#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = 0;

	while (left <= right && right < n) {
		if (sum < s) {
			right++;
			sum += a[right];
		} else if (sum == s) {
			ans++;
			right++;
			sum += a[right];
		} else if (sum > s) {
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}