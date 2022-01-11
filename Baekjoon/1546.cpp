#include <iostream>

int main() {
	double n, m;
	double maxValue = 0;
	double sum = 0;
	double score[1001] = {};

	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> score[i];
		if (maxValue < score[i]) maxValue = score[i];
	}

	for (int i = 0; i < n; i++) {
		score[i] = score[i] / maxValue * 100;
		sum += score[i];
	}

	std::cout << sum / n;
}