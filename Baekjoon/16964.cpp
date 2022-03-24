#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[100000];
vector<int> dfs_order;
int c[100000];

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	dfs_order.push_back(x);
	for (int y : a[x]) {
		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> b(n);
	vector<int> o(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		o[b[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end(), [&](int a, int b) { return o[a] < o[b]; });
	}

	dfs(0);

	if (dfs_order == b) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}

	return 0;
}
