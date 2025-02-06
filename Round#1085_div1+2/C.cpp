//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	using ll = long long;
	void solve() {
		int n, h;
		cin >> n >> h;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		matrix<ll> ps(n, vector<ll>(n)), ss{ps};
		for (int i{0}; i < n; ++i) {
			ps[i][i] = h - v[i];
			for (int j{i - 1}; j >= 0; --j) ps[i][j] = min(ps[i][j + 1], h - v[j]);
			for (int j{i + 1}; j < n; ++j) ps[i][j] = min(ps[i][j - 1], h - v[j]);
			for (int j{0}; j < n; ++j) ss[i][j] = ps[i][j];
			for (int j{1}; j < n; ++j) ps[i][j] += ps[i][j - 1];
			for (int j{n - 2}; j >= 0; --j) ss[i][j] += ss[i][j + 1];
		}

		ll ans{ss[0][0]};
		auto calc{[&](int i, int j, int k) { return ps[i][j] + ss[k][j + 1]; }};
		for (int i{0}; i < n; ++i)
			for (int k{i + 1}; k < n; ++k) {
				int l{i}, r{k - 1};
				while (l < r) {
					int m{(l + r) / 2};
					if (calc(i, m, k) < calc(i, m + 1, k)) l = m + 1;
					else r = m;
				}
				ans = max(ans, calc(i, l, k));
			}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
