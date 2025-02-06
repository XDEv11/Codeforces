//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D {
	using ll = long long;
	ll PM{998244353};
	ll MA(ll a, ll b) { return (a + b) % PM; }
	ll MS(ll a, ll b) { return (a - b + PM) % PM; }
	ll MM(ll a, ll b) { return (a * b) % PM; }

	vector<vector<int>> adj{};
	vector<ll> dp{};
	void dfs(int u, int w = -1) {
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
		dp[u] = 1;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dp[u] = MM(dp[u], MA(dp[v], 1));
		}
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {}), dp.resize(n);
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ll ans{1};
		dfs(0);
		for (auto& x : dp) ans = MA(ans, x);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D::solve();
}
