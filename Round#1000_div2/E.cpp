//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;

	int n;
	vector<vector<int>> adj{};
	vector<int> pa{}, dp{}, sz{};
	void dfs(int u, int w = -1) {
		pa[u] = w;
		dp[u] = (w == -1 ? 0 : dp[w] + 1);
		sz[u] = 1;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
	void solve() {
		cin >> n;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), dp.resize(n), sz.resize(n), dfs(0);

		vector<int> cnt(n + 1);
		for (auto& x : dp) ++cnt[x];
		for (int i{n - 1}; i >= 0; --i) cnt[i] += cnt[i + 1];

		ll ans{};
		for (int v{0}; v < n; ++v) {
			int x{dp[v]};
			ans += ll(2 * x - 1) * (cnt[x + 1] - (sz[v] - 1)) * 2;
			ans += ll(2 * x - 1) * (cnt[x] - cnt[x + 1] - 1);
		}
		for (int u{0}; u < n; ++u) {
			int x{dp[u]};
			for (auto& v : adj[u]) {
				if (v == pa[u]) continue;
				ans -= ll(2 * x) * sz[v] * (sz[u] - sz[v] - 1);
			}
		}
		ans /= 2;

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
