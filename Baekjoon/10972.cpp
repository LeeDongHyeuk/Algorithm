#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutation(vector<int> &a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i--;
	if (i <= 0) return false;

	int j = n - 1;
	while (a[j] <= a[i - 1]) j--;
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

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	if (next_permutation(num, n)) {
		for (int x : num) cout << x << ' ';
	} else {
		cout << -1;
	}
	cout << '\n';

	return 0;
}