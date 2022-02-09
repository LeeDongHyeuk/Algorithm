#include <iostream>

using namespace std;

int a[8];

void go(int idx, int start, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		a[idx] = i;
		go(idx + 1, i, n, m);
	}
}

/*
void go(int idx, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (idx > n) return;
	for (int i = m - selected; i >= 1; i--) {
		a[idx] = i;
		go(idx + 1, selected + i, n, m);
	}
	go(idx + 1, selected, n, m);
}
*/

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);

	return 0;
}