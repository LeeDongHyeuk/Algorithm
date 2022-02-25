#include <iostream>

using namespace std;

int num[20];

int main() {
	ios::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int ans = 0;

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += num[j];
			}
		}
		if (sum == s) {
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}

/*
#include <iostream>

using namespace std;

int n, s;
int num[20];
int ans = 0;

void go(int sum, int idx, int cnt) {
	if (idx == n) {
		if (sum == s && cnt > 0) {
			ans++;
		}
		return;
	}
	go(sum + num[idx], idx + 1, cnt + 1);
	go(sum, idx + 1, cnt);
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	go(0, 0, 0);
	cout << ans << '\n';

	return 0;
}
*/