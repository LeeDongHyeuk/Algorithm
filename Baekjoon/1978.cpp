#include <iostream>

using namespace std;

bool prime (int n) {
	if (n < 2) return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int cnt = 0;

	while (n--) {
		int x;
		cin >> x;

		if (prime(x)) cnt++;
	}

	cout << cnt;
}