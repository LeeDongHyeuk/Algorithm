#include <iostream>

int main() {
	int h, m;
	std::cin >> h >> m;

	if (m - 45 < 0) {
		h = (h == 0) ? 23 : --h;
		m = 15 + m;
	} else {
		m -= 45;
	}

	std::cout << h << " " << m;

	return 0;
}