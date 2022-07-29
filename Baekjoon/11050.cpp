#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	for (int i = 1; i <= m; i++) {
		ans /= i;
	}
	for (int i = 1; i <= n - m; i++) {
		ans /= i;
	}

	cout << ans << '\n';

	return 0;
}