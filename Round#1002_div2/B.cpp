//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		if (n == m) {
			for (int i{1}; ; ++i) {
				int j{1 + 2 * (i - 1)};
				if (j >= n || v[j] != i) return cout << i << '\n', []{}();
			}
		} else {
			for (int i{1}; i < 2 + n - m; ++i) {
				if (v[i] != 1) return cout << "1\n", []{}();
			}
			cout << "2\n";
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
