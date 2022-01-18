#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 메모리를 줄이거나 코드 길이를 줄이거나 시간을 줄이는 방식으로 여러가지로 풀어봄 백준 제출 기록 확인

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