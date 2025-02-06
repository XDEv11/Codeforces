//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#define fi first
#define se second

using namespace std;

namespace D {
	using ll = long long;

	int n, m;
	vector<ll> a{};
	vector<vector<int>> adj{};
	vector<int> pa{}, sz{}; vector<set<pair<int, int>>> ch{};
	void dfs(int u, int w = -1) {
		pa[u] = w, sz[u] = 1;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
			a[u] += a[v], sz[u] += sz[v], ch[u].emplace(-sz[v], v);
		}
	}
	void solve() {
		cin >> n >> m;
		a.resize(n), adj.assign(n, {});
		for (auto& x : a) cin >> x;
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), sz.resize(n), ch.assign(n, {});
		dfs(0);

		while (m--) {
			int op, y;
			cin >> op >> y, --y;

			if (op == 1) cout << a[y] << '\n';
			else if (op == 2) {
				if (ch[y].empty()) continue;
				int x{pa[y]}; ch[x].erase({-sz[y], y});
				auto [_, z]{*ch[y].begin()}; ch[y].erase(ch[y].begin());
				pa[y] = z, sz[y] -= sz[z], a[y] -= a[z], ch[z].emplace(-sz[y], y);
				pa[z] = x, sz[z] += sz[y], a[z] += a[y], ch[x].emplace(-sz[z], z);
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) D::solve();
}
