//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

namespace {
	vector<vector<int>> adj{};
	vector<int> pa{};
	vector<bool> tk{};
	array<int, 2> dfs(int u, int w = -1) {
		pa[u] = w;
		array<int, 2> mx{1, u};
		for (auto& v : adj[u]) {
			if (v == w || tk[v]) continue;
			auto [len, leaf]{dfs(v, u)};
			mx = max(mx, {len + 1, leaf});
		}
		return mx;
	}
	array<int, 3> tree_diameter(int u) {
		// assume 'b' and 'c' are endpoints of a tree diameter
		// choose a arbitrary node 'a'
		// let 'x' be the node that 'a' first meet path "b - c"
		// 'a' will finally find either 'b' or 'c' through 'x' as its longest path
		auto b{dfs(u)[1]};
		auto [l, c]{dfs(b)};
		return {l, max(b, c), min(b, c)};
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<array<int, 3>> ans{};
		pa.resize(n), tk.assign(n, false);
		queue<int> qu{};
		for (int v{0}; v < n; ++v) qu.push(v);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			if (tk[u]) continue;
			auto x{tree_diameter(u)};
			ans.push_back(x);
			int t{pa[x[1]] != -1 ? x[1] : x[2]};
			while (t != -1) tk[t] = true, t = pa[t];
			qu.push(u);
		}

		sort(ans.rbegin(), ans.rend());
		for (auto& [x, y, z] : ans) cout << x << ' ' << (y + 1) << ' ' << (z + 1) << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
