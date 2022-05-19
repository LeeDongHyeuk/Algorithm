#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	int now = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		now += a[i];
		ans += now;
	}

	cout << ans << '\n';

	return 0;
}