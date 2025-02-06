//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace F {
	int n, m;
	vector<vector<int>> adj{};
	vector<int> vis{};
	vector<array<int, 3>> ans{};
	bool dfs(int u, int w = -1) {
		vis[u] = 1;
		int x{-1};
		for (auto& v : adj[u]) {
			if (v == w || vis[v] == 1) continue;
			if (vis[v] == 0 && !dfs(v, u)) continue;
			if (x != -1) ans.push_back({x, u, v}), x = -1;
			else x = v;
		}
		vis[u] = 2;
		if (x != -1) {
			if (w != -1) ans.push_back({x, u, w});
			return false;
		} else return true;
	}
	bool solve() {
		if (!(cin >> n >> m)) return false;
		adj.assign(n, {});
		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vis.assign(n, 0), ans.clear();
		for (int v{0}; v < n; ++v) {
			if (vis[v]) continue;
			dfs(v);
		}

		cout << ans.size() << '\n';
		for (auto& [u, v, w] : ans) cout << (u + 1) << ' ' << (v + 1) << ' ' << (w + 1) << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (F::solve()) ;
}
