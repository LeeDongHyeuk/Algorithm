#include <iostream>
#include <algorithm>

using namespace std;

int num[8];
int a[8];

void go(int idx, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (idx >= n) return;
	a[selected] = num[idx];
	go(idx + 1, selected + 1, n, m);
	go(idx + 1, selected, n, m);
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	go(0, 0, n, m);

	return 0;
}