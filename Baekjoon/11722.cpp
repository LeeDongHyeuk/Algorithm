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

	reverse(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) d[i] = d[j] + 1;
		}
	}

	int ans = *max_element(d.begin(), d.end());
	cout << ans << '\n';

	return 0;
}