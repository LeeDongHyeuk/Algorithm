#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a[500000];

int binary_search(int num) {
	int l = 0;
	int r = n - 1;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == num) {
			return 1;
		} else if (a[mid] > num) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	cin >> m;
	while (m--) {
		int num;
		cin >> num;
		cout << binary_search(num) << '\n';
	}

	return 0;
}