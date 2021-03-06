#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
	int x, y;
};

bool cmp(const Point u, const Point v) {
	if (u.y < v.y) {
		return true;
	} else if (u.y == v.y) {
		return u.x < v.x;
	} else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].x << ' ' << a[i].y << '\n';
	}

	return 0;
}