#include <iostream> 

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;
	std::cout.precision(3);

	double c, n, cnt, sum, avg, result;

	std::cin >> c;

	for (int i = 0; i < c; i++) {
		std::cin >> n;
		sum = 0;
		cnt = 0;
		double score[1000];

		for (int j = 0; j < n; j++) {
			std::cin >> score[j];
			sum += score[j];
		}

		avg = sum / n;

		for (int k = 0; k < n; k++) {
			if (score[k] > avg) cnt++;
		}

		result = (cnt / n) * 100;

		std::cout << result << "%\n";
	}
}