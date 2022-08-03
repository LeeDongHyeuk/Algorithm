#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<bool> c(n + 1);
	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (!c[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				c[j] = true;
			}
		}
	}

	int left = 0;
	int right = 0;
	int sum = prime.empty() ? 0 : prime[0];
	int ans = 0;

	while (left <= right && right < prime.size()) {
		if (sum < n) {
			sum += prime[++right];
		} else if (sum > n) {
			sum -= prime[left++];
		} else {
			ans++;
			sum += prime[++right];
		}
	}

	cout << ans << '\n';

	return 0;
}