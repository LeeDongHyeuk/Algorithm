#include <iostream>

int main() {
	int x;
	int count[42] = {};
	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		std::cin >> x;
		count[x % 42]++;
	}

	for (int num : count) {
		if (num != 0) cnt++;
	}

	std::cout << cnt;
}