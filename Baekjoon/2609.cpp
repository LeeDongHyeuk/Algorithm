#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;

	int gcdNum = gcd(a, b);
	int lcmNum = gcdNum * (a / gcdNum) * (b / gcdNum);

	cout << gcdNum << "\n" << lcmNum;
}