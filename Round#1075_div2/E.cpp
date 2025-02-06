//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) {
			char c;
			cin >> c;
			x = (c == '1' ? 1 : -1);
		}
		if (n == 1) return void(cout << (v[0] == 1 ? "0\n" : "-1\n"));

		int d{};
		for (int i{0}; i < n; ++i) d += v[i];
		if (d == -n) return void(cout << "-1\n");
		if (d >= 0) return void(cout << n << '\n');

		if (d == -1) return void(cout << (n + 1) << '\n');
		int mx{}, s{};
		for (int i{0}; i < n; ++i) {
			mx = max(mx, s = max(0, s - v[i]));
		}
		if (d + mx - 1 >= 0) return void(cout << (n + 1) << '\n');

		for (int i{0}; i + 1 < n; ++i) {
			if (v[i] == 1 && v[i + 1] == 1) return void(cout << (n + 2) << '\n');
		}
		if (v[1] == 1 || v[n - 2] == 1) return void(cout << (n + 2) << '\n');

		cout << (n + 3) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
