//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <numeric>

using namespace std;

namespace D {
	pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) { return {a.fi + b.fi, a.se + b.se}; }
	pair<int, int> operator+=(pair<int, int>& a, const pair<int, int>& b) { return a.fi += b.fi, a.se += b.se, a; }
	int n;
	vector<vector<int>> adj{};
	vector<array<pair<int, int>, 2>> dp{};
	vector<int> ans{};
	void dfs1(int u, int w = -1) {
		dp[u][0] = {0, -1};
		dp[u][1] = {1, -adj[u].size()};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs1(v, u);
			dp[u][0] += max(dp[v][0], dp[v][1]);
			dp[u][1] += dp[v][0];
		}
	}
	void dfs2(bool g, int u, int w = -1) {
		ans[u] = g ? adj[u].size() : 1;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs2(!g && dp[v][1] > dp[v][0], v, u);
		}
	}
	void solve() {
		cin >> n;
		adj.assign(n, {}), dp.resize(n), ans.resize(n);
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	
		if (n == 2) return cout << "2 2\n1 1\n", []{}();

		dfs1(0);
		dfs2(dp[0][1] > dp[0][0], 0);

		if (dp[0][1] > dp[0][0]) cout << dp[0][1].fi << ' ' << -dp[0][1].se << '\n';
		else cout << dp[0][0].fi << ' ' << -dp[0][0].se << '\n';
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) D::solve();
}
