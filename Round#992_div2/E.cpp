//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
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

	vector<vector<int>> adj{};
	vector<int> pa{};
	void dfs(int u, int w = -1) {
		pa[u] = w;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
	}
	void solve() {
		int n, q;
		cin >> n >> q;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), dfs(0);

		while (q--) {
			int v, c;
			cin >> v >> c, --v;

			int s{};
			vector<int> t{};
			while (v > 0) {
				++s, v = pa[v];
				if (!v) break;
				t.push_back(adj[v].size()), v = pa[v];
			}

			sort(t.rbegin(), t.rend());
			for (auto& x : t) {
				if (c) --c, ++s;
				else s += (x - 1) * 2 + 1;
			}

			cout << s << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
