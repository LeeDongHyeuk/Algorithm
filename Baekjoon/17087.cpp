#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<int> bro(n);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		bro[i] = a < s ? (a - s) * -1 : a - s;
	}

	int d = bro[0];

	for (int i = 1; i < n; i++) {
		d = gcd(d, bro[i]);
	}

	cout << d;

	return 0;
}