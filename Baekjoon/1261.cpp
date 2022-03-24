#include <cstdio>
#include <deque>

using namespace std;

int a[100][100];
int d[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}
	}

	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	d[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (d[nx][ny] == -1) {
					if (a[nx][ny] == 0) {
						d[nx][ny] = d[x][y];
						q.push_front(make_pair(nx, ny));
					} else {
						d[nx][ny] = d[x][y] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}

	printf("%d\n", d[m - 1][n - 1]);
	return 0;
}