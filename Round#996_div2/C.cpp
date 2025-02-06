//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> a(n + m - 2);
		for (auto& x : a) cin >> x;
		vector<vector<ll>> t(n, vector<ll>(m));
		for (auto& v : t)
			for (auto& x : v) cin >> x;

		for (int i{0}, j{0}, k{0}; k <= n + m - 2; ++(k == n + m - 2 || a[k] == 'D' ? i : j), ++k) {
			ll x{};
			if (k == n + m - 2 || a[k] == 'R') {
				for (int ii{0}; ii < n; ++ii) x += t[ii][j];
			} else {
				for (int jj{0}; jj < m; ++jj) x += t[i][jj];
			}
			t[i][j] = -x;
		}

		for (auto& v : t) {
			for (auto& x : v) cout << x << ' ';
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
