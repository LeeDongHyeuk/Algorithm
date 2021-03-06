#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool c[8];
int num[8];
int a[8];
vector<vector<int>> d;

void go(int idx, int n, int m) {
	if (idx == m) {
		vector<int> temp;
		for (int i = 0; i < m; i++) {
			temp.push_back(a[i]);
		}
		d.push_back(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			a[idx] = num[i];
			c[i] = true;
			go(idx + 1, n, m);
			c[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	go(0, n, m);
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	for (auto& v : d) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}