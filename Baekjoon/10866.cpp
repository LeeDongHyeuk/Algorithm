#include <iostream>
#include <string>

using namespace std;

struct Deque {
	int data[40000];
	int begin, end;

	Deque() {
		begin = 20000;
		end = 20000;
	}

	void push_front(int x) {
		data[--begin] = x;
	}

	void push_back(int x) {
		data[end++] = x;
	}

	int size() {
		return end - begin;
	}

	int empty() {
		return size() == 0 ? 1 : 0;
	}

	int pop_front() {
		return !empty() ? data[begin++] : -1;
	}

	int pop_back() {
		return !empty() ? data[end-- - 1] : -1;
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

	Deque d;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		} else if (cmd == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		} else if (cmd == "pop_front") {
			cout << d.pop_front() << '\n';
		} else if (cmd == "pop_back") {
			cout << d.pop_back() << '\n';
		} else if (cmd == "size") {
			cout << d.size() << '\n';
		} else if (cmd == "empty") {
			cout << d.empty() << '\n';
		} else if (cmd == "front") {
			cout << d.front() << '\n';
		} else if (cmd == "back") {
			cout << d.back() << '\n';
		}
	}

	return 0;
}