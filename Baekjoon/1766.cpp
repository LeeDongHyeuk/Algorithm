#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[100001];
int ind[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		ind[y] += 1;
	}

	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(-i);
		}
	}

	while (!q.empty()) {
		int x = -q.top();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			ind[y] -= 1;
			if (ind[y] == 0) {
				q.push(-y);
			}
		}
	}
	cout << '\n';

	return 0;
}