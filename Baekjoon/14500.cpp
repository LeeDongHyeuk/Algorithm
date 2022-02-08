#include <iostream>

using namespace std;

int a[500][500];

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 3 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				if (ans < temp) ans = temp;
			}

			if (i + 3 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				if (ans < temp) ans = temp;
			}

			if (i + 1 < n && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}

			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i][j + 1];
					int temp3 = temp + a[i + 1][j + 1];
					int temp4 = temp + a[i + 2][j + 1];
					if (ans < temp2) ans = temp2;
					if (ans < temp3) ans = temp3;
					if (ans < temp4) ans = temp4;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i][j - 1];
					int temp3 = temp + a[i + 1][j - 1];
					int temp4 = temp + a[i + 2][j - 1];
					if (ans < temp2) ans = temp2;
					if (ans < temp3) ans = temp3;
					if (ans < temp4) ans = temp4;
				}
			}

			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j];
					int temp3 = temp + a[i + 1][j + 1];
					int temp4 = temp + a[i + 1][j + 2];
					if (ans < temp2) ans = temp2;
					if (ans < temp3) ans = temp3;
					if (ans < temp4) ans = temp4;
				}
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j];
					int temp3 = temp + a[i - 1][j + 1];
					int temp4 = temp + a[i - 1][j + 2];
					if (ans < temp2) ans = temp2;
					if (ans < temp3) ans = temp3;
					if (ans < temp4) ans = temp4;
				}
			}

			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i + 1][j + 1] + a[i + 2][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i + 1][j - 1] + a[i + 2][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}

			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1];
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1] + a[i + 1][j + 2];
					if (ans < temp2) ans = temp2;
				}
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j + 1] + a[i - 1][j + 2];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}