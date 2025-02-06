//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	using ll = long long;
	void solve() {
		int n, m;
		cin >> n >> m;
		matrix<ll> g(n, vector<ll>(m));
		for (auto& v : g)
			for (auto& x : v) cin >> x;

		matrix<ll> fp(n, vector<ll>(m, numeric_limits<ll>::min())), bp{fp};
		fp[0][0] = g[0][0];
		auto maximize{[](ll& x, ll y) { x = max(x, y); }};
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) {
				if (i) maximize(fp[i][j], fp[i - 1][j] + g[i][j]);
				if (j) maximize(fp[i][j], fp[i][j - 1] + g[i][j]);
			}
		bp[n - 1][m - 1] = g[n - 1][m - 1];
		for (int i{n - 1}; i >= 0; --i)
			for (int j{m - 1}; j >= 0; --j) {
				if (i + 1 < n) maximize(bp[i][j], bp[i + 1][j] + g[i][j]);
				if (j + 1 < m) maximize(bp[i][j], bp[i][j + 1] + g[i][j]);
			}

		ll ans{numeric_limits<ll>::max()};
		for (int j{0}; j < m; ++j) {
			vector<ll> umx(n, numeric_limits<ll>::min()), dmx{umx};
			for (int i{0}; i < n; ++i) {
				if (i) umx[i] = umx[i - 1];
				if (j + 1 < m) maximize(umx[i], fp[i][j] + bp[i][j + 1]);
			}
			for (int i{n - 1}; i >= 0; --i) {
				if (i + 1 < n) dmx[i] = dmx[i + 1];
				if (j) maximize(dmx[i], fp[i][j - 1] + bp[i][j]);
			}
			for (int i{n - 1}; i >= 0; --i) {
				ll mx{fp[i][j] + bp[i][j] - g[i][j] * 3};
				if (i) maximize(mx, umx[i - 1]);
				if (i + 1 < n) maximize(mx, dmx[i + 1]);
				ans = min(ans, mx);
			}
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
