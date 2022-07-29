#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int d[50];
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= 45; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	int n;
	cin >> n;
	cout << d[n] << '\n';

	return 0;
}