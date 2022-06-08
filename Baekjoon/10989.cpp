#include <iostream>

using namespace std;

int cnt[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int temp = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cnt[temp]++;
	}

	for (int i = 0; i <= 10000; i++) {
		if (cnt[i] > 0) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}