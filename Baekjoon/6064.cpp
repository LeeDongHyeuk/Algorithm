#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int ans = -1;
		for (int i = x; i <= m * n; i += m) {
			if ((i - 1) % n + 1 == y) {
				ans = i;
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}