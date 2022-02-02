#include <iostream>

using namespace std;

int a[1000];
int d[1000];
int v[1000];

void print(int x) {
	if (x == -1) return;
	print(v[x]);
	cout << a[x] << ' ';
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int ans = d[0];
	int p = 0;

	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i;
		}
	}

	cout << ans << '\n';
	print(p);

	return 0;
}