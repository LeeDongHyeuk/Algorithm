#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		int k;
		cin >> k;
		if (k == 0) break;

		vector<int> a(k);
		vector<int> n(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			if (i - 5 > 0) n[i] = 1;
			else n[i] = 0;
		}

		do {
			for (int j = 0; j < k; j++) {
				if (n[j] == 0) cout << a[j] << ' ';
			}
			cout << '\n';
		} while (next_permutation(n.begin(), n.end()));
		cout << '\n';
	}

	return 0;
}