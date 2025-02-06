//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <set>
#include <algorithm>

using namespace std;

// Hopcroft & Tarjan
namespace F {
	vector<vector<int>> adj{};
	vector<int> dep{}, low{};
	set<pair<int, int>> bridge{};
	void dfs0(int u, int w = -1, int d = 1) {
		low[u] = dep[u] = d;
		for (auto& v : adj[u]) {
			if (v == w || dep[v] >= dep[u]) continue;
			if (!dep[v]) { // tree edge
				dfs0(v, u, d + 1);
				low[u] = min(low[u], low[v]);
				if (low[v] > dep[u]) bridge.emplace(u, v);
			} else low[u] = min(low[u], dep[v]); // back edge
		}
	}
	set<pair<int, int>> ans{};
	vector<vector<int>> component{};
	vector<int> idx{};
	void dfs1(int u, int w = -1, int d = 1) {
		component.back().push_back(u), idx[u] = component.size() - 1;
		dep[u] = d;
		for (auto& v : adj[u]) {
			if (bridge.count({u, v}) || bridge.count({v, u})) continue;
			if (v == w || dep[v] >= dep[u]) continue;
			ans.emplace(u, v);
			if (!dep[v]) dfs1(v, u, d + 1);
		}
	}
	void dfs2(int u, int w = -1) {
		for (auto& x : component[u])
			for (auto& y : adj[x]) {
				if (!(bridge.count({x, y}) || bridge.count({y, x}))) continue;
				int v{idx[y]};
				if (v == w) continue;
				ans.emplace(y, x);
				dfs2(v, u);
			}
	}
	bool solve() {
		int n, m;
		if (!(cin >> n >> m)) return false;
		adj.assign(n, {});
		vector<pair<int, int>> edges{};
		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			edges.emplace_back(u, v);
		}

		dep.assign(n, 0), low.resize(n), dfs0(0);

		ans.clear(), dep.assign(n, 0), component.clear(), idx.resize(n);
		int mx{0}, mxi;
		for (int w{0}; w < n; ++w) {
			if (dep[w]) continue;
			component.emplace_back(), dfs1(w);
			if (component.back().size() > mx) mx = component.back().size(), mxi = component.size() - 1;
		}

		dfs2(mxi);

		cout << mx << '\n';
		for (auto& [u, v] : edges) {
			if (ans.count({u, v})) cout << (u + 1) << ' ' << (v + 1) << '\n';
			else cout << (v + 1) << ' ' << (u + 1) << '\n';
		}
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (F::solve()) ;
}
