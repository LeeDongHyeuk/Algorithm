#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	while (n >= 2 && m >= 1 && m + n >= k + 3) {
		ans++;
		n -= 2;
		m -= 1;
	}

	cout << ans << '\n';

	return 0;
}