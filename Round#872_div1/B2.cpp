//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

static const ll pm{1000000007};
static inline ll madd(ll a, ll b) { return (a + b) % pm; }
static inline ll msub(ll a, ll b) { return (a - b + pm) % pm; }
static inline ll mmlt(ll a, ll b) { return (a * b) % pm; }
static inline ll mpow(ll a, ll b) {
	ll res{1};
	do {
		if (b & 1) res = mmlt(res, a);
	} while (a = mmlt(a, a), b >>= 1);
	return res;
}
static inline ll minv(ll a) { return mpow(a, pm - 2); }
static inline ll mdiv(ll a, ll b) { return mmlt(a, minv(b)); }

const int maxn{200000};
static const vector<ll> fac{[] {
	vector<ll> v(maxn + 1);
	v[0] = 1;
	for (int i{1}; i <= maxn; ++i) v[i] = mmlt(v[i - 1], i);
	return v;
}()};
static inline ll mC(ll n, ll m) {
	if (n < 0 || clamp(m, 0ll, n) != m) return 0;
	return mdiv(fac[n], mmlt(fac[m], fac[n - m]));
}

namespace B2 {
	ll n, k;
	vector<vector<int>> adj{};
	vector<ll> sz{};
	ll dfs(int u = 0, int w = -1) {
		sz[u] = 1;
		ll c{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			c = madd(c, dfs(v, u));
			sz[u] = madd(sz[u], sz[v]);
		}
		c = madd(c, mmlt(mC(sz[u], k / 2), mC(n - sz[u], k / 2)));
		return c;
	}
	void solve() {
		cin >> n >> k;
		adj.assign(n, {}), sz.resize(n);
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		if (k & 1) return cout << "1\n", []{}();
		cout << madd(1, mdiv(dfs(), mC(n, k))) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) B2::solve();
}
