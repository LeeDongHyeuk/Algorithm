#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int x) {
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int next = a[x][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << ' ';
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(v);
	cout << '\n';
	memset(check, false, sizeof(check));
	bfs(v);
	cout << '\n';

	return 0;
}