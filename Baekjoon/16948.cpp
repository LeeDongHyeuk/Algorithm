#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int check[200][200];

int bfs(int x, int y, int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (check[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}

	return check[r][c];
}

int main() {
	cin >> n;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	memset(check, -1, sizeof(check));
	cout << bfs(r1, c1, r2, c2) << '\n';

	return 0;
}