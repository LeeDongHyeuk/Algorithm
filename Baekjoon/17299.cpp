#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int freq[1000001] = {}; // 메모리 초과로 밖에

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}

	stack<int> s;

	for (int i = 0; i < n; i++) {
		while (!s.empty() && freq[a[s.top()]] < freq[a[i]]) {
			ans[s.top()] = a[i];
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}