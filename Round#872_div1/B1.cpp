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

namespace B1 {
	ll n, k;
	vector<vector<int>> adj{};
	vector<ll> sz{};
	ll dfs1(int u = 0, int w = -1) {
		sz[u] = 1;
		ll c{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			c = madd(c, dfs1(v, u));
			sz[u] = madd(sz[u], sz[v]);
		}
		return c = madd(c, sz[u]);
	}
	ll dfs2(ll c, int u = 0, int w = -1) {
		ll s{c};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			s = madd(s, dfs2(msub(madd(c, msub(n, sz[v])), sz[v]), v, u));
		}
		return s;
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

		if (k != 2) return cout << "1\n", []{}();

		cout << mdiv(dfs2(msub(dfs1(), 1)), mmlt(n, n - 1)) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) B1::solve();
}
