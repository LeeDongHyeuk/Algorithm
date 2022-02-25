#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[20001];
int check[20001];

void dfs(int start, int c) {
	check[start] = c;
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];
		if (check[next] == 0) dfs(next, 3 - c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	while (k--) {
		int v, e;
		cin >> v >> e;

		for (int i = 1; i <= v; i++) {
			a[i].clear();
			check[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			int n, m;
			cin >> n >> m;
			a[n].push_back(m);
			a[m].push_back(n);
		}

		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) dfs(i, 1);
		}

		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int t = a[i][j];
				if (check[i] == check[t]) {
					ok = false;
					break;
				}
			}
		}

		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}