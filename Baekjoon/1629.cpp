#include <iostream>

using namespace std;

long long mul1(long long a, long long b, long long c) {
	if (b == 0) {
		return 1LL;
	} else if (b == 1) {
		return a % c;
	} else if (b % 2 == 0) {
		long long temp = mul1(a, b / 2, c);
		return (temp * temp) % c;
	} else {
		return (a * mul1(a, b - 1, c)) % c;
	}
}

long long mul2(long long a, long long b, long long c) {
	long long ans = 1LL;

	while (b > 0) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= c;
		}
		a = a * a;
		b /= 2;
		a %= c;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << mul1(a, b, c) << '\n';

	return 0;
}