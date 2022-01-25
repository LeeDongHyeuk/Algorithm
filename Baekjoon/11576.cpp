#include <iostream>

using namespace std;

void convert(int num, int base) {
	if (num == 0) return;
	convert(num / base, base);
	cout << num % base << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, m;
	cin >> a >> b >> m;

	int ans = 0;

	while (m--) {
		int n;
		cin >> n;
		ans = ans * a + n;
	}

	convert(ans, b);

	return 0;
}