//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D1 {
	vector<vector<int>> adj{};
	vector<int> dp{};
	void dfs(int u, int w = -1) {
		dp[u] = 0;
		int x{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			dp[u] += dp[v];
			if (!dp[v]) ++x;
		}
		dp[u] += max(0, x - 1);
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		dp.resize(n);
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if (n == 1) return cout << "0\n", []{}();

		for (int u{0}; u < n; ++u)
			if (adj[u].size() >= 3) {
				dfs(u);
				cout << dp[u] << '\n';
				return ;
			}
		cout << "1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D1::solve();
}
