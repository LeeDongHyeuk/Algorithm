#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	int s = 0;
	int x;

	while (m--) {
		string str;
		cin >> str;

		if (str == "add") {
			cin >> x;
			x--;
			s = s | (1 << x);
		} else if (str == "check") {
			cin >> x;
			x--;
			if (s & (1 << x)) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		} else if (str == "remove") {
			cin >> x;
			x--;
			if (s & (1 << x)) {
				s = s & ~(1 << x);
			}
		} else if (str == "toggle") {
			cin >> x;
			x--;
			s = s ^ (1 << x);
		} else if (str == "empty") {
			s = 0;
		} else if (str == "all") {
			s = (1 << 20) - 1;
		}
	}
	return 0;
}