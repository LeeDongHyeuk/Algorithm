#include <iostream>
#include <algorithm>

using namespace std;

int num[8];
int a[8];

void go(int idx, int start, int k, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < k; i++) {
		a[idx] = num[i];
		go(idx + 1, i, k, m);
	}
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int temp[8];

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + n);
	
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && temp[i] == temp[i - 1]) continue;
		num[k++] = temp[i];
	}

	go(0, 0, k, m);

	return 0;
}