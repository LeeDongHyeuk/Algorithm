#include <iostream>

int main() {
	int n;

	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for (int i = n; i >= 1; i--) {
		std::cout << i << "\n";
	}
}