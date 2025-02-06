//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	int n;
	vector<ll> a{};
	vector<vector<int>> adj{};
	vector<array<ll, 20>> dp{}, ps{}, ss{};
	void dfs(int u, int w = -1) {
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
		for (int k{1}; k <= 19; ++k) dp[u][k] = a[u] * k;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			for (int k{1}; k <= 19; ++k) dp[u][k] += min(ps[v][k], ss[v][k]);
		}
		ps[u][1] = numeric_limits<ll>::max();
		for (int k{1}; k + 1 <= 19; ++k) ps[u][k + 1] = min(ps[u][k], dp[u][k]);
		ss[u][19] = numeric_limits<ll>::max();
		for (int k{19}; k - 1 >= 1; --k) ss[u][k - 1] = min(ss[u][k], dp[u][k]);
	}
	void solve() {
		cin >> n;
		a.resize(n), adj.assign(n, {});
		for (auto& x : a) cin >> x;
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dp.resize(n), ps.resize(n), ss.resize(n), dfs(0);

		ll ans{numeric_limits<ll>::max()};
		for (int k{1}; k <= 19; ++k) ans = min(ans, dp[0][k]);

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
