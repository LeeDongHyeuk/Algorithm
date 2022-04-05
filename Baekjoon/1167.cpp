#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {
	}
};

vector<Edge> a[100001];
int dist[100001];

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
	int v;
	scanf("%d", &v);

	for (int i = 0; i < v; i++) {
		int x;
		scanf("%d", &x);

		while (true) {
			int y, z;
			scanf("%d", &y);
			if (y == -1) break;
			scanf("%d", &z);
			a[x].push_back(Edge(y, z));
		}
	}

	bfs(1);
	int start = 1;
	for (int i = 2; i <= v; i++) {
		if (dist[i] > dist[start]) {
			start = i;
		}
	}

	bfs(start);
	int ans = dist[1];
	for (int i = 2; i <= v; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}