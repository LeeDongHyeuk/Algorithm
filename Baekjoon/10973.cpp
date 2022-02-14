#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool previous_permutation(vector<int> &a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i--;
	if (i <= 0) return false;

	int j = n - 1;
	while (a[i - 1] <= a[j]) j--;
	swap(a[i - 1], a[j]);

	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (previous_permutation(a, n)) {
		for (int x : a) cout << x << ' ';
	} else {
		cout << -1;
	}
	cout << '\n';

	return 0;
}