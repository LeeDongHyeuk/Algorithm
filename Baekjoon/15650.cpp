#include <iostream>

using namespace std;

bool c[10];
int a[10];

void go(int idx, int selected, int n, int m) {
	if (selected == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (idx > n) return;
	a[selected] = idx;
	go(idx + 1, selected + 1, n, m);
	a[selected] = 0;
	go(idx + 1, selected, n, m);
}

/*
* 조금 더 비효율적인 버전
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
		go(idx + 1, i + 1, n, m);
	}
}
*/

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);
	//go(0, 1, n, m);
	return 0;
}