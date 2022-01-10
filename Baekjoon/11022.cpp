#include <iostream>

int main() {
	int t, a, b;

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::cin >> a >> b;
		std::cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << "\n";
	}
}