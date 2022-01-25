#include <iostream>
#include <stack>

using namespace std;

/*
int main() {
	int n, b;
	cin >> n >> b;

	stack<int> bstr;

	while (n > 0) {
		bstr.push(n % b);
		n /= b;
	}

	while (!bstr.empty()) {
		if (bstr.top() > 9) {
			cout << (char)(bstr.top() - 10 + 'A');
		} else {
			cout << bstr.top();
		}
		bstr.pop();
	}

	return 0;
}
*/

void convert(int num, int base) {
	if (num == 0) return;

	convert(num / base, base);

	int n = num % base;
	if (n > 9) cout << (char)(n - 10 + 'A');
	else cout << n;
}

int main() {
	int n, b;
	cin >> n >> b;

	convert(n, b);

	return 0;
}