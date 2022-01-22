#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void calc(stack<double> &s, char oper) {
	double y = s.top();
	s.pop();
	double x = s.top();
	s.pop();

	if (oper == '+') {
		s.push(x + y);
	} else if (oper == '-') {
		s.push(x - y);
	} else if (oper == '*') {
		s.push(x * y);
	} else if (oper == '/') {
		s.push(x / y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string str;
	cin >> str;

	vector<double> number(n);

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	stack<double> s;

	for (char ch : str) {
		if (ch >= 'A' && ch <= 'Z') {
			s.push(number[ch - 'A']);
		} else {
			calc(s, ch);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}