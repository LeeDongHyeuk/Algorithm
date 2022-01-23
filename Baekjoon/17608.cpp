#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<int> s;

	while (n--) {
		int x;
		cin >> x;

		while (!s.empty() && s.top() <= x) {
			s.pop();
		}

		s.push(x);
	}

	cout << s.size();
}