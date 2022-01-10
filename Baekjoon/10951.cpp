#include <iostream>

int main() {
	int a, b;

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (std::cin >> a >> b) { // 북마크한 글 참고
		std::cout << a + b << "\n";
	}
}