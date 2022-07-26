#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int children[4];
	int pi;
	int cnt;
	Node() {
		for (int i = 0; i < 4; i++) {
			children[i] = -1;
		}
		cnt = 0;
		pi = -1;
	}
};

int to_node(char x) {
	if (x == 'A') return 0;
	else if (x == 'T') return 1;
	else if (x == 'G') return 2;
	else if (x == 'C') return 3;
	else return 4;
}

vector<Node> trie;

int init() {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

void add(int node, string& s, int index) {
	if (index == s.size()) {
		trie[node].cnt = 1;
		return;
	}
	int c = to_node(s[index]);
	if (trie[node].children[c] == -1) {
		int next = init();
		trie[node].children[c] = next;
	}
	add(trie[node].children[c], s, index + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		trie.clear();
		int n, m;
		cin >> n >> m;
		string s, p;
		cin >> s >> p;

		int root = init();
		vector<string> a;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				string p2 = p;
				reverse(p2.begin() + i, p2.begin() + j + 1);
				a.push_back(p2);
			}
		}

		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		for (string& s : a) {
			add(root, s, 0);
		}

		queue<int> q;
		trie[root].pi = root;
		q.push(root);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int next = trie[cur].children[i];
				if (next == -1) continue;
				if (cur == root) {
					trie[next].pi = root;
				} else {
					int x = trie[cur].pi;
					while (x != root && trie[x].children[i] == -1) {
						x = trie[x].pi;
					}
					if (trie[x].children[i] != -1) {
						x = trie[x].children[i];
					}
					trie[next].pi = x;
				}
				int pi = trie[next].pi;
				trie[next].cnt += trie[pi].cnt;
				q.push(next);
			}
		}

		int ans = 0;
		int node = root;
		for (int i = 0; i < s.size(); i++) {
			int c = to_node(s[i]);
			while (node != root && trie[node].children[c] == -1) {
				node = trie[node].pi;
			}
			if (trie[node].children[c] != -1) {
				node = trie[node].children[c];
			}
			ans += trie[node].cnt;
		}

		cout << ans << '\n';
	}

	return 0;
}