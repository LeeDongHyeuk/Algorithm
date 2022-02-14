#include <iostream>
#include <algorithm>

using namespace std;

char ch[15];
char a[15];

int l, c;

void code(int idx, int selected, int ja, int mo) {
	if (selected == l && ja >= 2 && mo >= 1) {
		for (int i = 0; i < l; i++) {
			cout << a[i];
		}
		cout << '\n';
		return;
	}
	if (idx >= c) return;
	a[selected] = ch[idx];
	if (ch[idx] == 'a' || ch[idx] == 'e' || ch[idx] == 'i' || ch[idx] == 'o' || ch[idx] == 'u') {
		code(idx + 1, selected + 1, ja, mo + 1);
	} else {
		code(idx + 1, selected + 1, ja + 1, mo);
	}
	code(idx + 1, selected, ja, mo);
}

int main() {
	ios::sync_with_stdio(false);

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> ch[i];
	}

	sort(ch, ch + c);
	code(0, 0, 0, 0);

	return 0;
}