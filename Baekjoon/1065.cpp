#include <iostream>

using namespace std;

int hansu(int n) {
	int cnt;

	if (n < 100) {
		cnt = n;
	} else {
		cnt = 99;

		for (int i = 100; i <= n; i++) {
			int first = i / 100;
			int second = (i / 10) % 10;
			int third = i % 10;

			if ((first - second) == (second - third)) cnt++;
		}
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	cout << hansu(n);
}