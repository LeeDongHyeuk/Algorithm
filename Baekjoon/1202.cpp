#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct jewel {
	int m, v, w;
};

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	vector<jewel> a(n + k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].m, &a[i].v);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i + n].m);
		a[i + n].w = 1;
	}

	sort(a.begin(), a.end(), [](jewel u, jewel v) {
		return u.m < v.m || (u.m == v.m && u.w < v.w);
	});

	priority_queue<int> q;
	long long ans = 0;
	for (auto& p : a) {
		if (p.w == 0) {
			q.push(p.v);
		} else {
			if (!q.empty()) {
				ans += (long long)q.top();
				q.pop();
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}

/*
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct jewel {
	int m, v;
};

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	vector<jewel> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].m, &a[i].v);
	}

	sort(a.begin(), a.end(), [](jewel u, jewel v) {
		return u.v > v.v;
	});

	multiset<int> s;
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		s.insert(t);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(a[i].m);
		if (it != s.end()) {
			ans += a[i].v;
			s.erase(it);
		}
	}

	printf("%lld\n", ans);

	return 0;
}
*/