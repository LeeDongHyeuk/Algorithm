#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n + 1);
	vector<int> d(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		if (d[i] < d[i - 2] + a[i]) d[i] = d[i - 2] + a[i];
		if (d[i] < d[i - 3] + a[i] + a[i - 1]) d[i] = d[i - 3] + a[i] + a[i - 1];
	}

	cout << d[n] << '\n';

	return 0;
}