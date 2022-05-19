#include <cstdio>
#include <vector>

using namespace std;

void change(vector<int>& a, int idx) {
	for (int i = idx - 1; i <= idx + 1; i++) {
		if (0 <= i && i < a.size()) {
			a[i] = 1 - a[i];
		}
	}
}

pair<bool, int> go(vector<int> a, vector<int> b) {
	int n = a.size();
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i]) {
			change(a, i + 1);
			ans++;
		}
	}
	if (a == b) {
		return make_pair(true, ans);
	} else {
		return make_pair(false, ans);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%1d", &b[i]);
	}

	auto p1 = go(a, b);
	change(a, 0);
	auto p2 = go(a, b);
	if (p2.first) {
		p2.second++;
	}
	if (p1.first && p2.first) {
		printf("%d\n", min(p1.second, p2.second));
	} else if (p1.first) {
		printf("%d\n", p1.second);
	} else if (p2.first) {
		printf("%d\n", p2.second);
	} else {
		printf("-1\n");
	}


	return 0;
}