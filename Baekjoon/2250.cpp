#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int left, right;
	int order, depth;
};

Node a[10001];
int leftOrder[10001];
int rightOrder[10001];
int cnt[10001];
int order = 0;

void inorder(int node, int depth) {
	if (node == -1) return;
	inorder(a[node].left, depth + 1);
	a[node].order = ++order;
	a[node].depth = depth;
	inorder(a[node].right, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].left = y;
		a[x].right = z;
		if (y != -1) cnt[y]++;
		if (z != -1) cnt[z]++;
	}

	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) root = i;
	}

	inorder(root, 1);

	int maxDepth = 0;
	for (int i = 1; i <= n; i++) {
		int depth = a[i].depth;
		int order = a[i].order;
		
		if (leftOrder[depth] == 0) {
			leftOrder[depth] = order;
		} else {
			leftOrder[depth] = min(leftOrder[depth], order);
		}
		rightOrder[depth] = max(rightOrder[depth], order);
		maxDepth = max(maxDepth, depth);
	}

	int ans = 0;
	int ansLevel = 0;
	for (int i = 1; i <= maxDepth; i++) {
		if (ans < rightOrder[i] - leftOrder[i] + 1) {
			ans = rightOrder[i] - leftOrder[i] + 1;
			ansLevel = i;
		}
	}

	cout << ansLevel << ' ' << ans << '\n';
	return 0;
}