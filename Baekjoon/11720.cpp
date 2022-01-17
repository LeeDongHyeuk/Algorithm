#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string numStr;

	cin >> n;
	cin >> numStr;

	int sum = 0;

	for (int x : numStr) {
		sum += (x - '0');
	}

	cout << sum;
}