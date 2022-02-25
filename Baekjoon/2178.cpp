#include <cstdio>
#include <queue>

using namespace std;

int a[100][100];
int check[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}

	printf("%d\n", check[n - 1][m - 1]);

	return 0;
}