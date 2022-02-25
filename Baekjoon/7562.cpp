#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int l;
int a[300][300];
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	a[x][y] = 0;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (a[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					a[nx][ny] = a[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &l);
		memset(a, -1, sizeof(a));

		int x, y, mx, my;
		scanf("%d %d", &x, &y);
		scanf("%d %d", &mx, &my);

		bfs(x, y);
		printf("%d\n", a[mx][my]);
	}

	return 0;
}