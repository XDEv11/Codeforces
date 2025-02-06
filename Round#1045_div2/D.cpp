//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	vector<vector<int>> adj{};
	vector<int> p{};
	array<int, 2> dfs(int u, int w = -1) {
		p[u] = w;
		array<int, 2> mx{0, u};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			auto [len, leaf]{dfs(v, u)};
			mx = max(mx, {len + 1, leaf});
		}
		return mx;
	}
	array<int, 3> tree_diameter(int a = 0) {
		// assume 'b' and 'c' are endpoints of a tree diameter
		// choose a arbitrary node 'a'
		// let 'x' be the node that 'a' first meet path "b - c"
		// 'a' will finally find either 'b' or 'c' through 'x' as its longest path
		auto b{dfs(a)[1]};
		auto [l, c]{dfs(b)};
		return {l, b, c};
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v), adj[v].push_back(u);
		}

		p.resize(n);
		auto [_, d1, d2]{tree_diameter()};
		dfs(d1), p[d1] = d1;

		for (int x{p[d2]}, y{d2}; x != d1; y = x, x = p[x]) {
			if (adj[x].size() > 2) {
				for (auto& v : adj[x]) {
					if (v == y || v == p[x]) continue;
					cout << (p[x] + 1) << ' ' << (x + 1) << ' ' << (v + 1) << '\n';
					return ;
				}
			}
		}
		cout << "-1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
