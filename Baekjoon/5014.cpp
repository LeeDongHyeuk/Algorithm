#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dist[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int next = now + u;
		if (next <= f && dist[next] == -1) {
			dist[next] = dist[now] + 1;
			q.push(next);
		}

		next = now - d;
		if (next > 0 && dist[next] == -1) {
			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}

	if (dist[g] == -1) {
		cout << "use the stairs\n";
	} else {
		cout << dist[g] << '\n';
	}

	return 0;
}