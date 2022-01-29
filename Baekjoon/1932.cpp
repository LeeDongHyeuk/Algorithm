#include <iostream>
#include <algorithm>

using namespace std;

int a[501][501];
int d[501][501];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	d[1][1] = a[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max({ d[i][j], d[i - 1][j] + a[i][j], d[i - 1][j - 1] + a[i][j] });
		}
	}

	int ans = 0;

	for (int i = 1; i < 501; i++) ans = max(ans, d[n][i]);

	cout << ans;

	return 0;
}