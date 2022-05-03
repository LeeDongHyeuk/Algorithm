#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dist[101];
int check[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n + m; i++) {
		int x, y;
		cin >> x >> y;
		check[x] = y;
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y <= 100) {
				if (check[y] != 0) y = check[y];
				if (dist[y] == -1) {
					dist[y] = dist[x] + 1;
					q.push(y);
				}
			}
		}
	}

	cout << dist[100] << '\n';
	return 0;
}