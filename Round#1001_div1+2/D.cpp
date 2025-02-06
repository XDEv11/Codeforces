//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	int n;
	vector<pair<int, int>> r{};
	vector<vector<int>> adj{};
	vector<int> pa{}, a{};
	void dfs(int u, int w = -1) {
		pa[u] = w;
		int mx{};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			mx = max(mx, a[v]);
		}
		a[u] = clamp(mx, r[u].fi, r[u].se);
	}
	void solve() {
		cin >> n;
		r.resize(n);
		for (auto& [x, y] : r) cin >> x >> y;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), a.resize(n), dfs(0);

		long long ans{a[0]};
		for (int v{1}; v < n; ++v) ans += max(0, a[v] - a[pa[v]]);

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
