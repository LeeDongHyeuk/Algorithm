#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	set<string> s;

	while (n--) {
		string name, what;
		cin >> name >> what;
		if (what == "enter") {
			s.insert(name);
		} else {
			s.erase(s.find(name));
		}
	}

	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << '\n';
	}

	return 0;
}