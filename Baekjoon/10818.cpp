#include <iostream>

int main() {
	int n, x;
	int maxValue = -1000001;
	int minValue = 1000001;

	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> x;

		if (x > maxValue) maxValue = x;
		if (x < minValue) minValue = x;
	}

	std::cout << minValue << " " << maxValue;
	
	// Ǯ �� �ִ� ����� ���� ������ �ϸ�ũ �س��� �ۿ��� �پ��ϰ� ���� ���� ����
}