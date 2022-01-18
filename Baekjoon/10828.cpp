#include <iostream>
#include <string>

using namespace std;

struct Stack {
	int data[10000];
	int size;

	Stack() {
		size = 0;
	}

	void push(int x) {
		data[size++] = x;
	}

	bool empty() {
		return size == 0 ? true : false;
	}

	int pop() {
		return !empty() ? data[--size] : -1;
	}

	int top() {
		return !empty() ? data[size - 1] : -1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Stack s;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x;
			cin >> x;
			s.push(x);
		} else if (cmd == "pop") {
			cout << s.pop() << "\n";
		} else if (cmd == "size") {
			cout << s.size << "\n";
		} else if (cmd == "empty") {
			cout << s.empty() << "\n";
		} else if (cmd == "top") {
			cout << s.top() << "\n";
		}
	}

	return 0;
}