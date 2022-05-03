#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dist[10000];
int from[10000];
char how[10000];

void print(int n, int m) {
	if (n == m) return;
	print(n, from[m]);
	cout << how[m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		memset(dist, -1, sizeof(dist));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));

		queue<int> q;
		q.push(a);
		dist[a] = 0;
		from[a] = -1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			int next = (now * 2) % 10000;
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'D';
			}
			next = now - 1;
			if (next == -1) next = 9999;
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'S';
			}
			next = (now % 1000) * 10 + (now / 1000);
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'L';
			}
			next = (now % 10) * 1000 + (now / 10);
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'R';
			}
		}
		print(a, b);
		cout << '\n';
	}
	return 0;
}