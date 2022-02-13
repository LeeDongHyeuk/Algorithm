#include <iostream>
#include <algorithm>

using namespace std;

bool c[8];
int num[8];
int a[8];

void go(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			a[idx] = num[i];
			c[i] = true;
			go(idx + 1, n, m);
			c[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	go(0, n, m);

	return 0;
}