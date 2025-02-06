//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{998244353};
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
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n);
		for (auto& x : a) cin >> x;
		vector<vector<int>> adj(n);
		for (int i{0}; i < m; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[v].push_back(u);
		}

		vector<pair<ll, int>> t(n);
		for (int v{0}; v < n; ++v) t[v] = {a[v], v};
		sort(t.begin(), t.end());

		vector<map<ll, ll>> c(n);
		auto MAA{[](ll& x, ll y) { x = MA(x, y); }};
		for (auto& [_, v] : t)
			for (auto& u : adj[v]) MAA(c[v][a[u] + a[v]], MA(c[u][a[v]], 1));

		ll ans{};
		for (int v{0}; v < n; ++v)
			for (auto& [_, x] : c[v]) ans = MA(ans, x);
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
