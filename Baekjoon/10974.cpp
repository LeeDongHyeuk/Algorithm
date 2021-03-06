#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = i + 1;

	do {
		for (int x : a) cout << x << ' ';
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}