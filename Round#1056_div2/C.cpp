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
		for (auto& x : v) cin >> x;
		if (n == 1) return cout << (v[0] == 1 ? 2 : 0) << '\n', []{}();

		vector<int> c(n, -1);

		for (int i{0}; i + 1 < n; ++i) {
			if (v[i + 1] == v[i] + 1) {
				if (c[i] != -1 && c[i] != 0) return cout << "0\n", []{}();
				c[i] = c[i + 1] = 0;
			} else if (v[i + 1] == v[i] - 1) {
				if (c[i] != -1 && c[i] != 1) return cout << "0\n", []{}();
				c[i] = c[i + 1] = 1;
			} else if (v[i + 1] == v[i]) {
				if (c[i] != -1) c[i + 1] = (c[i] == 0 ? 1 : 0);
			} else return cout << "0\n", []{}();
		}
		if (c[n - 1] == -1) {
			int a{};
			if (v[0] - 1 == n / 2) ++a;
			if (v[0] - 1 == (n - 1) / 2) ++a;
			return cout << a << '\n', []{}();
		}

		for (int i{n - 1}; i - 1 >= 0; --i) {
			if (c[i] != -1 && c[i - 1] == -1) c[i - 1] = (c[i] == 0 ? 1 : 0);
		}
		int d{1};
		for (int i{1}; i < n; ++i) d += (c[i] == 1);
		if (v[0] != d) return cout << "0\n", []{}();
		cout << "1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
