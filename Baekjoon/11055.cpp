#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + a[i] > d[i]) d[i] = d[j] + a[i];
		}
	}

	int ans = *max_element(d.begin(), d.end());
	cout << ans << '\n';

	return 0;
}