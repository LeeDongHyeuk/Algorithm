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
	
	// 풀 수 있는 방법이 많기 때문에 북마크 해놓은 글에서 다양하게 보는 것이 좋음
}