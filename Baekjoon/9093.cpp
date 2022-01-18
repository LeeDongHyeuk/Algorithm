#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;
	cin.ignore();

	while (t--) {
		string str;
		getline(cin, str);

		str += "\n";
		stack<char> s;

		for (char ch : str) {
			if (ch != ' ' && ch != '\n') {
				s.push(ch);
			} else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
		}
	}
	
	return 0;
}