#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
bool check[MAX];
int dist[MAX];

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	dist[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x - 1 >= 0) {
			if (check[x - 1] == false) {
				check[x - 1] = true;
				q.push(x - 1);
				dist[x - 1] = dist[x] + 1;
			}
		}
		if (x + 1 < MAX) {
			if (check[x + 1] == false) {
				check[x + 1] = true;
				q.push(x + 1);
				dist[x + 1] = dist[x] + 1;
			}
		}
		if (x * 2 < MAX) {
			if (check[x * 2] == false) {
				check[x * 2] = true;
				q.push(x * 2);
				dist[x * 2] = dist[x] + 1;
			}
		}
	}

	cout << dist[k] << '\n';
	return 0;
}