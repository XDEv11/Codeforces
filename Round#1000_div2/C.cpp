//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	vector<vector<int>> adj{};
	int ans;
	int dfs(int u = 0, int w = -1) {
		int mx{};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			int r{dfs(v, u)}, t{max(int(adj[v].size()), r)};

			ans = max(ans, int(adj[u].size()) + int(adj[v].size()) - 2);
			if (r) ans = max(ans, int(adj[u].size()) + r - 1);
			if (mx) ans = max(ans, mx + t - 1);

			mx = max(mx, t);
		}
		return mx;
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ans = 0, dfs();
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
