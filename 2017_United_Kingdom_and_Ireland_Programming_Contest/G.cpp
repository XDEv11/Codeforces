//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	array<int, 6> a, b;
	for (auto& x : a) {
		if (!(cin >> x)) return false;
	}
	for (auto& x : b) cin >> x;

	auto adjust{[&a, &b](int k) {
		if (a[k] == a[k + 3] && b[k] == b[k + 3]) return false;
		if (a[k] < a[k + 3]) ++a[k];
		else if (a[k] > a[k + 3]) --a[k];
		if (b[k] < b[k + 3]) ++b[k];
		else if (b[k] > b[k + 3]) --b[k];
		return true;
	}};
	auto print{[&a, &b] {
		cout << '(' << a[0] << ' ' << a[1] << ' ' << a[2] << ')';
		cout << ' ';
		cout << '(' << b[0] << ' ' << b[1] << ' ' << b[2] << ')';
		cout << '\n';
	}};

	print();
	if (a[0] != b[0]) {
		while (adjust(1)) print();
		while (adjust(2)) print();
		if (a[4] == b[4] && a[5] == b[5]) ++a[1], print();
		while (adjust(0)) print();
		if (a[4] == b[4] && a[5] == b[5]) --a[1], print();
	} else if (a[1] != b[1]) {
		while (adjust(0)) print();
		while (adjust(2)) print();
		if (a[3] == b[3] && a[5] == b[5]) ++a[0], print();
		while (adjust(1)) print();
		if (a[3] == b[3] && a[5] == b[5]) --a[0], print();
	} else {
		while (adjust(0)) print();
		while (adjust(1)) print();
		if (a[3] == b[3] && a[4] == b[4]) ++a[0], print();
		while (adjust(2)) print();
		if (a[3] == b[3] && a[4] == b[4]) --a[0], print();
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
