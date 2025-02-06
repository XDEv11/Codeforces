//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

namespace dsu_on_tree {
	void solve() {
		using ll = long long;

		int n, m;
		cin >> n >> m;
		vector<int> p(n); iota(p.begin(), p.end(), 1);
		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;
			p[u] = max(p[u], v);
		}

		ll ans{};

		vector<int> dp(n);
		for (int v{n - 2}; v >= 0; --v) dp[v] = dp[p[v]] + 1;
		vector<int> sz(n, 1);
		for (int v{0}; v < n - 1; ++v) {
			ans -= ll(sz[v]) * sz[p[v]] * dp[p[v]];
			sz[p[v]] += sz[v];
		}
		sort(dp.begin(), dp.end());
		for (int i{0}; i < n; ++i) ans += ll(n - (i + 1)) * dp[i];

		vector<vector<vector<int>>> ch(n);
		for (int v{0}; v < n; ++v) {
			vector<int> t{};
			int mx{}, j;
			for (int i{0}; i < ch[v].size(); ++i) {
				if (ch[v][i].size() > mx) mx = ch[v][i].size(), j = i;
			}
			if (mx) {
				t = move(ch[v][j]);
				for (int i{0}; i < ch[v].size(); ++i) {
					if (i == j) continue;
					m = ch[v][i].size();
					for (int k{1}; k <= m; ++k) {
						ans += ll(ch[v][i][m - k]) * t[mx - k] * k;
						t[mx - k] += ch[v][i][m - k];
					}
				}
			}

			if (v < n - 1) {
				t.push_back(1);
				ch[p[v]].push_back(move(t));
			}
		}

		cout << ans << '\n';
	}
};

namespace virtual_tree {
	using ll = long long;
	vector<list<int>> ch{};
	int r, d; // virtual tree of depth d, rooted at r
	vector<int> dp{}, c{};
	vector<ll> a{};
	int dfs(int u) { // build a virtual tree of depth d + 1 from one of depth d
		if (dp[u] == d) {
			c[u] = 1;
			return u;
		}

		for (auto it{ch[u].begin()}; it != ch[u].end(); ) {
			auto ni{next(it)};
			int v{dfs(*it)};
			if (v != -1) {
				*it = v;
				a[u] += ll(d - dp[u]) * c[u] * c[v];
				c[u] += c[v], c[v] = 0;
			} else ch[u].erase(it);
			it = ni;
		}
		if (ch[u].empty()) return -1;
		if (ch[u].size() == 1) {
			int v{ch[u].front()};
			c[v] = c[u], c[u] = 0;
			return v;
		}
		return u;
	}
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> p(n); iota(p.begin(), p.end(), 1);
		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;
			p[u] = max(p[u], v);
		}
		ch.assign(n, {});
		for (int v{0}; v < n - 1; ++v) ch[p[v]].push_back(v);

		ll ans{};
		dp.resize(n), dp[n - 1] = 0;
		for (int v{n - 2}; v >= 0; --v) dp[v] = dp[p[v]] + 1;
		{
			vector<int> t(n, 1);
			for (int v{0}; v < n - 1; ++v) ans -= ll(t[v]) * t[p[v]] * dp[p[v]], t[p[v]] += t[v];
			t = dp, sort(t.begin(), t.end());
			for (int i{0}; i < n; ++i) ans += ll(n - (i + 1)) * t[i];
		}

		c.resize(n), a.assign(n, 0);
		for (r = n - 1, d = 0; r != -1; ) c[r] = 0, ++d, r = dfs(r);
		for (auto& x : a) ans += x;

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) virtual_tree::solve();
}
