#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
char a[20];
bool c[10];
vector<string> ans;

bool ok(char x, char y, char op) {
	if (op == '<') {
		if (x > y) return false;
	}
	if (op == '>') {
		if (x < y) return false;
	}
	return true;
}

void go(int idx, string num) {
	if (idx == k + 1) {
		ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (c[i]) continue;
		if (idx == 0 || ok(num[idx - 1], i + '0', a[idx - 1])) {
			c[i] = true;
			go(idx + 1, num + to_string(i));
			c[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	go(0, "");

	auto p = minmax_element(ans.begin(), ans.end());

	cout << *p.second << '\n';
	cout << *p.first << '\n';
	return 0;
}