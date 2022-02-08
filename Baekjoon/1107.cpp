#include <iostream>

using namespace std;

bool check[10];

int possible(int c) {
	if (c == 0) {
		if (check[c]) return 0;
		else return 1;
	}

	int len = 0;
	while (c > 0) {
		if (check[c % 10]) return 0;
		c /= 10;
		len += 1;
	}

	return len;
}

int main() {
	int n, m;
	cin >> n >> m;

	while (m--) {
		int x;
		cin >> x;
		check[x] = true;
	}

	int ans = n - 100;
	if (ans < 0) ans = -ans;

	for (int i = 0; i <= 1000000; i++) {
		int len = possible(i);

		if (len > 0) {
			int press = n - i;
			if (press < 0) press = -press;
			if (ans > press + len) ans = press + len;
		}
	}

	cout << ans << '\n';
	return 0;
}