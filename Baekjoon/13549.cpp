#include <iostream>
#include <deque>

using namespace std;

const int MAX = 100001;
bool c[MAX];
int d[MAX];

int main() {
	int n, k;
	cin >> n >> k;

	c[n] = true;
	d[n] = 0;
	deque<int> q;
	q.push_back(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop_front();

		if (now * 2 < MAX) {
			if (c[now * 2] == false) {
				q.push_front(now * 2);
				c[now * 2] = true;
				d[now * 2] = d[now];
			}
		}

		if (now - 1 >= 0) {
			if (c[now - 1] == false) {
				q.push_back(now - 1);
				c[now - 1] = true;
				d[now - 1] = d[now] + 1;
			}
		}

		if (now + 1 < MAX) {
			if (c[now + 1] == false) {
				q.push_back(now + 1);
				c[now + 1] = true;
				d[now + 1] = d[now] + 1;
			}
		}
	}

	cout << d[k] << '\n';
	return 0;
}