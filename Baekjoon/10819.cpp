#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());


	int ans = 0;
	do {
		int temp = 0;
		for (int i = 1; i < n; i++) {
			temp += abs(a[i - 1] - a[i]);
		}
		ans = max(ans, temp);
	} while (next_permutation(a.begin(), a.end()));

	cout << ans << '\n';
	return 0;
}