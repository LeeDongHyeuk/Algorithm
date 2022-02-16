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