//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	auto calc{[](int x, int y) {
		int c{};
		while (x) {
			if (y && x >= 2 * y) {
				int t{x / (2 * y)};
				c += t * 3;
				x -= t * 2 * y;
			} else if (y >= 2 * x) {
				int t{y / (2 * x)};
				c += 3 * t;
				y -= t * 2 * x;
			} else {
				c += 1;
				int t{abs(x - y)};
				x = y, y = t;
			}
		}
		return c;
	}};

	bool f0{true}, f1{true}, f2{true};
	for (int i{0}; i < n; ++i) {
		if (a[i] || b[i]) {
			auto c{calc(a[i], b[i])};
			if (c % 3 != 0) f0 = false;
			if (c % 3 != 1) f1 = false;
			if (c % 3 != 2) f2 = false;
		}
	}
	cout << (f0 || f1 || f2 ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
