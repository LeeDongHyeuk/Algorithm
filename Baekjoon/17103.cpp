#include <iostream>
#include <vector>

using namespace std;

bool check[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> primes;

	check[0] = check[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (check[i] == false) {
			primes.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int gold = 0;

		for (int i = 0; primes[i] <= n / 2; i++) {
			if (check[n - primes[i]] == false) gold++;
		}

		cout << gold << '\n';
	}

	return 0;
}