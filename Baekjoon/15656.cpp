#include <iostream>
#include <algorithm>

using namespace std;

int num[7];
int a[7];

void go(int idx, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		a[idx] = num[i];
		go(idx + 1, n, m);
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