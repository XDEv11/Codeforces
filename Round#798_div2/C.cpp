//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace C {
	int n;
	vector<vector<int>> adj{};
	vector<int> sz{}, dp{};

	void dfs(int u, int w = -1) {
		sz[u] = 1;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			sz[u] += sz[v];
		}

		dp[u] = 0;
		int s{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			s += dp[v];
		}
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dp[u] = max(dp[u], sz[v] - 1 + s - dp[v]);
		}
	}

	void solve() {
		cin >> n;
		adj.assign(n, {}), sz.resize(n), dp.resize(n);
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0);

		cout << dp[0] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) C::solve();
}
