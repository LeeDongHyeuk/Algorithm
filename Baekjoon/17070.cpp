#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

int a[100][100];
int n;

int go(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		return 1;
	}

	int ans = 0;
	if (dir == 0) { // -
		if (y + 1 < n && a[x][y + 1] == 0) {
			ans += go(x, y + 1, 0);
		}
		if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) {
			ans += go(x + 1, y + 1, 1);
		}
	} else if (dir == 1) { // dig
		if (y + 1 < n && a[x][y + 1] == 0) {
			ans += go(x, y + 1, 0);
		}
		if (x + 1 < n && a[x + 1][y] == 0) {
			ans += go(x + 1, y, 2);
		}
		if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) {
			ans += go(x + 1, y + 1, 1);
		}
	} else if (dir == 2) { // |
		if (x + 1 < n && a[x + 1][y] == 0) {
			ans += go(x + 1, y, 2);
		}
		if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) {
			ans += go(x + 1, y + 1, 1);
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << go(0, 1, 0) << '\n';

	return 0;
}