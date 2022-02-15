#include <iostream>
#include <vector>

using namespace std;

int player[20][20];
int n;

int go(int idx, vector<int>& first, vector<int>& second) {
	if (idx == n) {
		if (first.size() == 0) return -1;
		if (second.size() == 0) return -1;

		int t1 = 0;
		int t2 = 0;
		for (int i = 0; i < first.size(); i++) {
			for (int j = 0; j < first.size(); j++) {
				if (i == j) continue;
				t1 += player[first[i]][first[j]];
			}
		}
		for (int i = 0; i < second.size(); i++) {
			for (int j = 0; j < second.size(); j++) {
				if (i == j) continue;
				t2 += player[second[i]][second[j]];
			}
		}
		int diff = abs(t1 - t2);
		return diff;
	}
	
	int ans = -1;
	first.push_back(idx);
	int t1 = go(idx + 1, first, second);
	if (ans == -1 || (t1 != -1 && ans > t1)) {
		ans = t1;
	}
	first.pop_back();
	second.push_back(idx);
	int t2 = go(idx + 1, first, second);
	if (ans == -1 || (t2 != -1 && ans > t2)) {
		ans = t2;
	}
	second.pop_back();

	return ans;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> player[i][j];
		}
	}
	
	vector<int> first, second;
	cout << go(0, first, second) << '\n';

	return 0;
}