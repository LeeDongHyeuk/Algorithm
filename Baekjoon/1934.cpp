#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int gcdNum = gcd(a, b);

		cout << gcdNum * (a / gcdNum) * (b / gcdNum) << "\n";
	}
}