#include <iostream>

int b[50];

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int ans = 0;
	while (true) {
		bool isZero = true;
		bool isOdd = false;

		for (int i = 0; i < n; i++) {
			if (b[i]) isZero = false;
			if (b[i] % 2) {
				b[i]--;
				ans++;
				isOdd = true;
				break;
			}
		}

		if (isZero) break;
		if (isOdd) continue;;

		for (int i = 0; i < n; i++) {
			b[i] /= 2;
		}
		ans++;
	}

	cout << ans << '\n';

	return 0;
}