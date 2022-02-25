#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];
		if (!check[next]) dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}