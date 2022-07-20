#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	set<string> s;

	while (n--) {
		string name;
		cin >> name;
		s.insert(name);
	}

	set<string> ans;
	while (m--) {
		string name;
		cin >> name;

		if (s.count(name)) {
			ans.insert(name);
		}
	}

	cout << ans.size() << '\n';
	for (auto name = ans.begin(); name != ans.end(); name++) {
		cout << *name << '\n';
	}

	return 0;
}