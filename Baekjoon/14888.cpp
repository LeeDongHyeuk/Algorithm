#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> marks;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			marks.push_back(i);
		}
	}

	sort(marks.begin(), marks.end());

	do {
		int sum = num[0];
		for (int i = 0; i < n - 1; i++) {
			if (marks[i] == 0) {
				sum += num[i + 1];
			} else if (marks[i] == 1) {
				sum -= num[i + 1];
			} else if (marks[i] == 2) {
				sum *= num[i + 1];
			} else if (marks[i] == 3) {
				sum /= num[i + 1];
			}
		}
		ans.push_back(sum);
	} while (next_permutation(marks.begin(), marks.end()));

	auto p = minmax_element(ans.begin(), ans.end());
	cout << *p.second << '\n';
	cout << *p.first << '\n';

	return 0;
}