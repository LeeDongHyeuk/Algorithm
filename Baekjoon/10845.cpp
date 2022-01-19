#include <iostream>
#include <string>

using namespace std;

struct Queue {
	int data[10000];
	int begin = 0;
	int end = 0;

	void push(int x) {
		data[end++] = x;
	}

	int size() {
		return end - begin;
	}

	int empty() {
		return size() == 0 ? 1 : 0;
	}

	int pop() {
		return !empty() ? data[begin++] : -1;
	}

	int front() {
		return !empty() ? data[begin] : -1;
	}

	int back() {
		return !empty() ? data[end - 1] : -1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	Queue q;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x;
			cin >> x;

			q.push(x);
		} else if (cmd == "pop") {
			cout << q.pop() << '\n';
		} else if (cmd == "size") {
			cout << q.size() << '\n';
		} else if (cmd == "empty") {
			cout << q.empty() << '\n';
		} else if (cmd == "front") {
			cout << q.front() << '\n';
		} else if (cmd == "back") {
			cout << q.back() << '\n';
		}
	} 

	return 0;
}