#include <iostream>

int main() {
	double a, b;
	std::cin >> a >> b;

	std::cout.precision(15); // �Ǽ� ��ü �ڸ��� �� n�ڸ� ���� ǥ��
	std::cout << a / b;

	return 0;
}