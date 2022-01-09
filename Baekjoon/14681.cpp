#include <iostream>

int main() {
	int a, b, n;
	std::cin >> a >> b;

	if (a > 0)
		if (b > 0) n = 1;
		else n = 4;
	else
		if (b > 0) n = 2;
		else n = 3;

	std::cout << n;

	return 0;
}