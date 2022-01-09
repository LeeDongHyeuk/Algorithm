#include <iostream>

int main() {
	double a, b;
	std::cin >> a >> b;

	std::cout.precision(15); // 실수 전체 자리수 중 n자리 까지 표현
	std::cout << a / b;

	return 0;
}