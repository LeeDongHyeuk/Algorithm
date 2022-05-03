#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int a[1000][1000];
int d[1000][1000][2];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	d[0][0][0] = 1;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny][z] == 0 && a[nx][ny] == 0) {
					d[nx][ny][z] = d[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				if (d[nx][ny][z + 1] == 0 && a[nx][ny] == 1 && z == 0) {
					d[nx][ny][z + 1] = d[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}

	if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0) {
		cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
	} else if (d[n - 1][m - 1][0] != 0) {
		cout << d[n - 1][m - 1][0];
	} else if (d[n - 1][m - 1][1] != 0) {
		cout << d[n - 1][m - 1][1];
	} else {
		cout << -1;
	}
	cout << '\n';

	return 0;
}