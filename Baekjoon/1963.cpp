#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

bool prime[10000];
int dist[10000];

int change(int num, int idx, int digit) {
	if (idx == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[idx] = digit + '0';
	return stoi(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 2; i < 10000; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < 10000; j += i) {
				prime[j] = true;
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		memset(dist, -1, sizeof(dist));

		queue<int> q;
		q.push(a);
		dist[a] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if (next != -1) {
						if (prime[next] == false && dist[next] == -1) {
							q.push(next);
							dist[next] = dist[now] + 1;
						}
					}
				}
			}
		}
		
		if (dist[b] == -1) {
			cout << "Impossible" << '\n';
		} else {
			cout << dist[b] << '\n';
		}
	}

	return 0;
}