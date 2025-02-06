//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		for (auto& x : c) cin >> x;

		int c0{}, c1{};
		for (int j{0}; j < n; ++j) {
			bool f{true};
			for (int i{0}; i < n; ++i) {
				if (a[i] >= b[(j + i) % n]) { f = false; break; }
			}
			c0 += f;
		}

		for (int k{0}; k < n; ++k) {
			bool f{true};
			for (int j{0}; j < n; ++j) {
				if (b[j] >= c[(k + j) % n]) { f = false; break; }
			}
			c1 += f;
		}

		cout << (ll(n) * c0 * c1) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
