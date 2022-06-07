#include <iostream>

using namespace std;

int a[1000000];
int b[1000000];
int c[2000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < n || j < m) {
		if ((j >= m) || (i < n && a[i] <= b[j])) {
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
		}
	}

	for (int i = 0; i < n + m; i++) {
		cout << c[i] << ' ';
	}
	cout << '\n';

	return 0;
}