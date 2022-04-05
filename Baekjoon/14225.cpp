#include <iostream>

using namespace std;

int a[20];
bool c[100000 * 20 + 1];
int n;

void go(int cnt, int sum) {
	if (cnt == n) {
		if (cnt == n) {
			c[sum] = true;
			return;
		}
	}

	go(cnt + 1, sum + a[cnt]);
	go(cnt + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	go(0, 0);

	for (int i = 1; ; i++) {
		if (c[i] == false) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}