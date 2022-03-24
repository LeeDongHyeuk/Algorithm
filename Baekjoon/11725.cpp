#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
vector<int> a[MAX];
int parent[MAX];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int y : a[x]) {
			if (parent[y] == 0) {
				parent[y] = x;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}