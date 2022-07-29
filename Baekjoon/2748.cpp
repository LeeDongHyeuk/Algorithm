#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long d[100];
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i < 100; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	int n;
	cin >> n;
	cout << d[n] << '\n';

	return 0;
}