//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	int n;
	vector<ll> a{};
	vector<vector<int>> adj{};
	vector<ll> dp0{}, dp1{};
	void dfs(int u, int w = -1) {
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
		dp0[u] = 0, dp1[u] = a[u];
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dp0[u] += max(dp0[v], dp1[v]);
			dp1[u] += dp0[v];
		}
	}
	void solve() {
		cin >> n;
		a.resize(n), adj.assign(n, {}), dp0.resize(n), dp1.resize(n);
		for (auto& x : a) cin >> x;
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0);
		ll ans{accumulate(a.begin(), a.end(), 0ll) + max(dp0[0], dp1[0])};

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
