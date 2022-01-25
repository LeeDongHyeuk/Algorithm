#include <iostream>
#include <string>

using namespace std;

int main() {
	string n;
	int b;

	cin >> n >> b;

	int ans = 0;

	for (int i = 0; i < n.length(); i++) {
		if (n[i] >= 'A' && n[i] <= 'Z') {
			ans = ans * b + (n[i] - 'A' + 10);
		} else {
			ans = ans * b + (n[i] - '0');
		}
	}

	cout << ans;

	return 0;
}