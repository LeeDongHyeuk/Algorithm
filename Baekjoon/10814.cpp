#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
	int age;
	string name;
	int join;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Person> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].age >> a[i].name;
		a[i].join = i;
	}

	sort(a.begin(), a.end(), [](Person u, Person v) {
		return (u.age < v.age) || (u.age == v.age && u.join < v.join);
	});

	for (int i = 0; i < n; i++) {
		cout << a[i].age << ' ' << a[i].name << '\n';
	}

	return 0;
}