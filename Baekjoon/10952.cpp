#include <iostream>

int main() {
	int a, b;

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (true) {
		std::cin >> a >> b;
		if (a == 0 && b == 0) break;
		std::cout << a + b << "\n";
	}
}