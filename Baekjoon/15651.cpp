#include <iostream>

using namespace std;

int n, m;
int a[7];

void go(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		a[idx] = i;
		go(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;
	go(0);

	return 0;
}