#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {};
};

vector<Edge> a[10001];
int dist[10001];

void bfs(int start) {
	memset(dist, -1, sizeof(dist));

	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (Edge e : a[x]) {
			if (dist[e.to] == -1) {
				dist[e.to] = dist[x] + e.cost;
				q.push(e.to);
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(Edge(y, z));
		a[y].push_back(Edge(x, z));
	}

	bfs(1);
	int start = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > dist[start]) {
			start = i;
		}
	}

	bfs(start);
	int ans = dist[1];
	for (int i = 2; i <= n; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}