//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{1000000007};
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int _{0}; _ < n - 1; ++_) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ll ans{};
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
	for (int i{1}; i < n; ++i) dp[i][0] = 1;
	for (int i{1}; i < n; ++i)
		for (int j{1}; j < n; ++j) dp[i][j] = MD(MA(dp[i - 1][j], dp[i][j - 1]), 2);
	for (int w{0}; w < n; ++w) {
		vector<int> d(n, -1), p(n, -1);
		vector<int> to{};
		queue<int> qu{};
		d[w] = 0, p[w] = w, qu.push(w);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			to.push_back(u);
			for (auto& v : adj[u]) {
				if (d[v] != -1) continue;
				d[v] = d[u] + 1, p[v] = u, qu.push(v);
			}
		}
		ll cnt{};
		vector<vector<int>> lca(n, vector<int>(n));
		for (int v{0}; v < n; ++v) lca[v][v] = v;
		for (int i{0}; i < n; ++i)
			for (int j{i + 1}; j < n; ++j) {
				int u{to[i]}, v{to[j]};
				if (u > v) swap(u, v);
				int l{lca[u][v] = lca[v][u] = d[u] <= d[v] ? lca[u][p[v]] : lca[p[u]][v]};
				cnt = MA(cnt, dp[d[u] - d[l]][d[v] - d[l]]);
			}
		ans = MA(ans, MD(cnt, n));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
