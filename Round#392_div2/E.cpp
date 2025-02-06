//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#include <cassert>

using namespace std;

namespace E {
	using ll = long long;
	int n;
	vector<vector<tuple<int, int, ll, ll>>> adj{};
	vector<ll> mn{}, mx{}, act{};
	bool dfs1(int u, int pa = -1) {
		mn[u] = 0, mx[u] = 0, act[u] = 0;
		for (auto& [v, i, w, p] : adj[u]) {
			if (v == pa) continue;
			if (!dfs1(v, u)) return false;
			if (p < mn[v]) return false;
			mn[u] += mn[v] + w - min(p - mn[v], w - 1);
			mx[u] += min(p, mx[v]) + w;
			act[u] += act[v] + w;
		}
		return true;
	}
	vector<tuple<int, int, ll, ll>> ans{};
	void dfs2(int u, ll r, int pa = -1) {
		ll d{act[u] - r};
		for (auto& [v, i, w, p] : adj[u]) {
			if (v == pa) continue;
			d -= act[v] - mx[v];
		}
		for (auto& [v, i, w, p] : adj[u]) {
			if (v == pa) continue;
			if (p < mx[v]) {
				d -= mx[v] - p, mx[v] = p;
			}
		}
		for (auto& [v, i, w, p] : adj[u]) {
			if (v == pa) continue;
			ll x{min({d, p - mx[v], w - 1})};
			w -= x, p -= x, d -= x;
		}
		for (auto& [v, i, w, p] : adj[u]) {
			if (v == pa) continue;
			ll x{min(d, mx[v] - mn[v] + min(mx[v] - mn[v], w - 1))};
			d -= x;
			if (x > mx[v] - mn[v]) {
				x -= mx[v] - mn[v];
				w -= x, p -= x;
				dfs2(v, mn[v], u);
			} else dfs2(v, mx[v] - x, u);
		}
		for (auto& [v, i, w, p] : adj[u]) {
			if (v == pa) continue;
			if (i > 0) ans[i - 1] = {u + 1, v + 1, w, p};
			else ans[-i - 1] = {v + 1, u + 1, w, p};
		}
	}
	bool solve() {
		if (!(cin >> n)) return false;
		adj.assign(n, {});
		for (int i{1}; i < n; ++i) {
			int u, v, w, p;
			cin >> u >> v >> w >> p, --u, --v;
			adj[u].emplace_back(v, i, w, p);
			adj[v].emplace_back(u, -i, w, p);
		}

		mn.resize(n), mx.resize(n), act.resize(n);
		if (!dfs1(0)) return cout << "-1\n", true;

		ans.resize(n - 1);
		dfs2(0, mx[0]);

		cout << n << '\n';
		for (auto& [u, v, w, p] : ans) cout << u << ' ' << v << ' ' << w << ' ' << p << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (E::solve()) ;
}
