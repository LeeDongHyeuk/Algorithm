#include <iostream>

int main() {
	int a, b;

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (std::cin >> a >> b) { // �ϸ�ũ�� �� ����
		std::cout << a + b << "\n";
	}
}