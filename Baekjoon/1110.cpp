#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	
	int n, tmp;
	int cnt = 0;

	std::cin >> n;
	tmp = n;

	do {
		tmp = (tmp % 10) * 10 + (tmp / 10 + tmp % 10) % 10;
		cnt++;
	} while (tmp != n);

	std::cout << cnt;
}