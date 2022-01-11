#include <iostream>

int main() {
	// 이것도 방법이 많으니 북마크 참고
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