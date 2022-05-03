#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (s == "P=NP") {
			cout << "skipped" << '\n';
		} else {
			int x, y;
			int plus = s.find('+');
			x = stoi(s.substr(0, plus));
			y = stoi(s.substr(plus + 1));
			cout << x + y << '\n';
		}
	}

	return 0;
}