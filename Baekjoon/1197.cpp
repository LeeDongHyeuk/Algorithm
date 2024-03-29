#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int from, to, cost;
	bool operator < (const Edge& other) const {
		return cost < other.cost;
	}
};

int p[10001];

int Find(int x) {
	if (x == p[x]) {
		return x;
	} else {
		return p[x] = Find(p[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	vector<Edge> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].from >> a[i].to >> a[i].cost;
	}

	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < m; i++) {
		Edge e = a[i];
		int x = Find(e.from);
		int y = Find(e.to);
		if (x != y) {
			Union(e.from, e.to);
			ans += e.cost;
		}	
	}

	cout << ans << '\n';

	return 0;
}