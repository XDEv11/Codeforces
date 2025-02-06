//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{1000000007};
	ll MC(ll a) { return (a % PM + PM) % PM; }
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
	ll& MAA(ll& a, ll b) { return a = MA(a, b); };
	ll& MSA(ll& a, ll b) { return a = MS(a, b); };
	ll& MMA(ll& a, ll b) { return a = MM(a, b); };
	ll& MDA(ll& a, ll b) { return a = MD(a, b); };

	vector<vector<int>> adj{};
	vector<int> c{}, s{};
	vector<map<int, ll>> dp{};
	void dfs(int u, int w = -1) {
		dp[u][c[u]] = 1;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);

			map<int, ll> t{};
			for (auto& [x1, y1] : dp[u])
				for (auto& [x2, y2] : dp[v]) {
					MAA(t[x1 ^ x2], MM(y1, y2));
					if (count(s.begin(), s.end(), x2)) MAA(t[x1], MM(y1, y2));
				}
			dp[u] = move(t);
		}
	}
	void solve() {
		int n, m;
		cin >> n >> m;
		adj.assign(n, {}), c.resize(n), s.resize(m);
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (auto& x : c) cin >> x;
		for (auto& x : s) cin >> x;

		ll ans{};
		dp.assign(n, {}), dfs(0);
		for (auto& [x, y] : dp[0]) {
			if (count(s.begin(), s.end(), x)) MAA(ans, y);
		}

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
