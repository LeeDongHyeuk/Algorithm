#include <iostream>

using namespace std;

int n, m;
char a[20][20];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int ans = 11;

void go(int cnt, int cx1, int cy1, int cx2, int cy2) {
	if (cnt == 10) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx1 = cx1 + dx[i];
		int ny1 = cy1 + dy[i];
		int nx2 = cx2 + dx[i];
		int ny2 = cy2 + dy[i];

		if (0 <= nx1 && nx1 < m && 0 <= ny1 && ny1 < n && 0 <= nx2 && nx2 < m && 0 <= ny2 && ny2 < n) {
			if (a[ny1][nx1] == '#' && a[ny2][nx2] == '#') {
				continue;
			} else if (a[ny1][nx1] == '#') {
				go(cnt + 1, cx1, cy1, nx2, ny2);
			} else if (a[ny2][nx2] == '#') {
				go(cnt + 1, nx1, ny1, cx2, cy2);
			} else {
				go(cnt + 1, nx1, ny1, nx2, ny2);
			}
		} else if ((0 > nx1 || nx1 >= m || 0 > ny1 || ny1 >= n) && (0 > nx2 || nx2 >= m || 0 > ny2 || ny2 >= n)) {
			continue;
		} else {
			if (ans > cnt + 1) ans = cnt + 1;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	int cx1, cy1, cx2, cy2;
	bool chk = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'o') {
				if (chk == false) {
					cx1 = j;
					cy1 = i;
					chk = true;
				} else {
					cx2 = j;
					cy2 = i;
				}
			}
		}
	}

	go(0, cx1, cy1, cx2, cy2);

	if (ans == 11) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}