#include <iostream>

int main() {
	int arr[9]; // ���� �迭�� �� �ʿ� ����� ��
	int maxValue = 0;
	int idx;

	for (int i = 0; i < 9; i++) {
		std::cin >> arr[i];

		if (arr[i] > maxValue) {
			maxValue = arr[i];
			idx = i;
		}
	}

	std::cout << maxValue << "\n" << idx + 1;
}