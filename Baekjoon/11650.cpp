#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int ,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		cout << a[i].first << ' ' << a[i].second << '\n';
	}

	return 0;
}