#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num[8];
int a[8];
vector<vector<int>> d;

void go(int idx, int selected, int n, int m) {
	if (selected == m) {
		vector<int> temp;

		for (int i = 0; i < m; i++) {
			temp.push_back(a[i]);
		}
		d.push_back(temp);
		return;
	}

	if (idx >= n) return;
	a[selected] = num[idx];
	go(idx + 1, selected + 1, n, m);
	go(idx + 1, selected, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);
	go(0, 0, n, m);
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	for (auto& v : d) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}