#include <iostream>
#include <string>

using namespace std;

int n;
int sign[10][10];
int ans[10];

bool check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += ans[i];
		if (sign[i][idx] == 0) {
			if (sum != 0) return false;
		} else if (sign[i][idx] > 0) {
			if (sum <= 0) return false;
		} else if (sign[i][idx] < 0) {
			if (sum >= 0) return false;
		}
	}
	return true;
}

bool go(int idx) {
	if (idx == n) {
		return true;
	}
	if (sign[idx][idx] == 0) {
		ans[idx] = 0;
		return check(idx) && go(idx + 1);
	}
	for (int i = 1; i <= 10; i++) {
		ans[idx] = sign[idx][idx] * i;
		if (check(idx) && go(idx + 1)) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;

	string str;
	cin >> str;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (str[cnt] == '0') {
				sign[i][j] = 0;
			} else if (str[cnt] == '+') {
				sign[i][j] = 1;
			} else {
				sign[i][j] = -1;
			}
			cnt++;
		}
	}
	
	go(0);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}