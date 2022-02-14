#include <iostream>

using namespace std;

int n;
int ans = 0;
int t[15];
int p[15];

void pay(int day, int sum) {
	if (day == n) {
		if (ans < sum) ans = sum;
		return;
	}
	if (day > n) return;

	pay(day + t[day], sum + p[day]);
	pay(day + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	pay(0, 0);
	cout << ans << '\n';

	return 0;
}