#include <iostream>
#include <string>

int OX(std::string& s) {
	int cnt = 0;
	int sum = 0;

	for (char& v : s) {
		if (v == 'O') {
			cnt++;
			sum += cnt;
		} else {
			cnt = 0;
		}
	}

	return sum;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;

		std::cout << OX(s) << "\n";
	}
}