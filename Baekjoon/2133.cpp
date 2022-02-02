#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> d(n + 1);
	d[0] = 1;

	for (int i = 2; i <= n; i += 2) {
		d[i] = 3 * d[i - 2];

		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
	}

	cout << d[n] << '\n';

	return 0;
}