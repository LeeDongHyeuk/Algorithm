#include <iostream>

using namespace std;

int d[12];

int go(int sum, int goal) {
	if (sum > goal) return 0;
	if (sum == goal) return 1;
	return go(sum + 1, goal) + go(sum + 2, goal) + go(sum + 3, goal);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		/*
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;

		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << '\n';
		*/
		cout << go(0, n) << '\n';
	}
}