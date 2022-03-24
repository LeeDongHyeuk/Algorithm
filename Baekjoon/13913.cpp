#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
bool check[MAX];
int dist[MAX];
int from[MAX];

void print(int n, int k) {
	if (n != k) {
		print(n, from[k]);
	}
	cout << k << ' ';
}

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
				from[x - 1] = x;
			}
		}
		if (x + 1 < MAX) {
			if (check[x + 1] == false) {
				check[x + 1] = true;
				q.push(x + 1);
				dist[x + 1] = dist[x] + 1;
				from[x + 1] = x;
			}
		}
		if (x * 2 < MAX) {
			if (check[x * 2] == false) {
				check[x * 2] = true;
				q.push(x * 2);
				dist[x * 2] = dist[x] + 1;
				from[x * 2] = x;
			}
		}
	}

	cout << dist[k] << '\n';
	print(n, k);
	cout << '\n';

	return 0;
}