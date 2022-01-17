#include <iostream>

using namespace std;

int d(int n) {
	int sum = n;

	while (n != 0) {
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

int main() {
	int arr[10001] = {};

	for (int i = 0; i < 10001; i++) {
		if (d(i) < 10001) arr[d(i)] = 1;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i] == 0) cout << i << "\n";
	}
}