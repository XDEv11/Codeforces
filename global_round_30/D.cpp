//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		vector<int> c(n);
		for (int j{n - 1}, i{n - 1}; j >= 0; --j) {
			i = min(i, j);
			while (i >= 0 && a[i] != b[j]) --i;
			if (i < 0) return cout << "-1\n", []{}();
			if (!c[i]) c[i] = j - i;
		}

		int t{*max_element(c.begin(), c.end())};
		if (t > m) return cout << "-1\n", []{}();

		cout << t << '\n';
		for (int k{0}; k < t; ++k) {
			for (int i{n - 1}; i >= 0; --i) {
				if (c[i]) a[i + 1] = a[i], --c[i];
			}
			rotate(c.begin(), prev(c.end()), c.end());

			for (auto& x : a) cout << x;
			cout << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
