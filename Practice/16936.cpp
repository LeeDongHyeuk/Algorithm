#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, long long>> a(n);
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		a[i].second = num;

		while (num % 3 == 0) {
			num /= 3;
			a[i].first++;
		}

		a[i].first = -a[i].first;
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i].second << ' ';
	}
	cout << '\n';

	return 0;
}