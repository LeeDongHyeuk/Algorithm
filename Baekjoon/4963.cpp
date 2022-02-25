#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int w, h;
int a[50][50];
bool group[50][50];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	group[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (a[nx][ny] == 1 && group[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
				group[i][j] = false;
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && group[i][j] == false) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}