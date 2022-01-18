#include <iostream>
#include <string>
#include <stack>

using namespace std;

// �޸𸮸� ���̰ų� �ڵ� ���̸� ���̰ų� �ð��� ���̴� ������� ���������� Ǯ� ���� ���� ��� Ȯ��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;
	bool check = false;
	string str;
	stack<int> s;

	while (n--) {
		int x;
		cin >> x;

		if (x > cnt) {
			while (x > cnt) {
				s.push(++cnt);
				str += "+";
			}
			
			s.pop();
			str += "-";
		} else {
			if (x == s.top()) {
				s.pop();
				str += "-";
			} else {
				check = true;
			}
		}
	}

	if (check) {
		cout << "NO";
		return 0;
	}

	for (char ch : str) {
		cout << ch << '\n';
	}

	return 0;
}