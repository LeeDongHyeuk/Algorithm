#include <iostream>

int main() {
	// �̰͵� ����� ������ �ϸ�ũ ����
	int a, b, c, sum;
	int arr[10] = {};

	std::cin >> a >> b >> c;
	sum = a * b * c;

	while (sum != 0) {
		arr[sum % 10]++;
		sum /= 10;
	}

	for (int num : arr) {
		std::cout << num << "\n";
	}
}