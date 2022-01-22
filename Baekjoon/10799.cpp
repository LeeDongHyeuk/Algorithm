#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;
	stack<int> s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(i);
		else {
			if (s.top() + 1 == i) {
				s.pop();
				cnt += s.size();
			} else {
				s.pop();
				cnt++;
			}
		}
	}

	cout << cnt;
}