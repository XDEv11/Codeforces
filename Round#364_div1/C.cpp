//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> pa, sz;
public:
	explicit DSU(int n) : pa(n, -1), sz(n, 1) {}
	int find(int x) { // collapsing find
		return pa[x] == -1 ? x : pa[x] = find(pa[x]);
	}
	void unionn(int x, int y) { // weighted union
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		pa[ry] = rx, sz[rx] += sz[ry];
	}
};

// Hopcroft & Tarjan
namespace C {
	vector<vector<array<int, 3>>> adj{};
	vector<int> dep{}, low{};
	int mn, mni;
	bool dfs(int t, int ig, int u, int p = -1, int d = 1) {
		bool f{u == t};
		low[u] = dep[u] = d;
		for (auto& [v, w, i] : adj[u]) {
			if (i == ig) continue; // ignore this edge
			if (i == p || dep[v] >= dep[u]) continue;
			if (!dep[v]) { // tree edge
				bool ff{dfs(t, ig, v, i, d + 1)};
				f = f || ff;
				low[u] = min(low[u], low[v]);
				if (ff && low[v] > dep[u]) { // bridge
					if (mn > w) mn = w, mni = i;
				}
			} else low[u] = min(low[u], dep[v]); // back edge
		}
		return f;
	}
	bool solve() {
		int n, m, s, t;
		if (!(cin >> n >> m >> s >> t)) return false;
		--s, --t;
		adj.assign(n, {});
		vector<array<int, 3>> edges(m);
		for (int i{0}; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w, --u, --v;
			adj[u].push_back({v, w, i});
			adj[v].push_back({u, w, i});
			edges[i] = {u, v, w};
		}

		dep.assign(n, 0), low.resize(n), dfs(-1, -1, s); // not connected
		if (!dep[t]) return cout << "0\n0\n", true;

		int ans{numeric_limits<int>::max()}, e1{-1}, e2;
		DSU dsu{n};
		for (int i{0}; i < m; ++i) {
			if (dsu.find(edges[i][0]) == dsu.find(edges[i][1])) continue;
			dsu.unionn(edges[i][0], edges[i][1]);
			dep.assign(n, 0), low.resize(n), mn = numeric_limits<int>::max(), mni = -1, dfs(t, i, s);
			if (!dep[t]) {
				if (edges[i][2] < ans) ans = edges[i][2], e1 = i, e2 = -1;
			} else if (mni != -1) {
				if (edges[i][2] + mn < ans) ans = edges[i][2] + mn, e1 = i, e2 = mni;
			}
		}
		if (e1 == -1) return cout << "-1\n", true;

		cout << ans << '\n';
		if (e2 == -1) cout << "1\n" << (e1 + 1) << '\n';
		else cout << "2\n" << (e1 + 1) << ' ' << (e2 + 1) << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (C::solve()) ;
}
