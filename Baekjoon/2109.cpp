#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Lecture {
	int p, d;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Lecture> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].p >> a[i].d;
	}
	sort(a.begin(), a.end(), [](Lecture u, Lecture v) {
		return u.d > v.d;
		});

	int k = 0;
	priority_queue<int> q;
	int ans = 0;
	for (int i = 10000; i >= 1; i--) {
		while (k < n && a[k].d == i) {
			q.push(a[k].p);
			k++;
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}

	cout << ans << '\n';

	return 0;
}