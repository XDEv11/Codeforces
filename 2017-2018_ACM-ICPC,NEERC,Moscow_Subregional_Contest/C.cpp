//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class HLD { // Heavy-Light Decomposition
	vector<int> pa, sz, dep, hv, hd;
	void heavy_light(const vector<vector<int>>& adj, int u, int w = -1, int d = 0) {
		pa[u] = w, sz[u] = 1, dep[u] = d;
		int mx{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			heavy_light(adj, v, u, d + 1);
			sz[u] += sz[v];
			if (sz[v] > mx) mx = sz[v], hv[u] = v;
		}
	}
	void decompose(const vector<vector<int>>& adj, int u, int h) {
		hd[u] = h;
		for (auto& v : adj[u]) {
			if (v == pa[u]) continue;
			if (v == hv[u]) decompose(adj, v, h);
			else decompose(adj, v, v);
		}
	}
public:
	HLD(const vector<vector<int>>& adj, int root) : pa(adj.size()), sz(adj.size()), dep(adj.size()), hv(adj.size(), -1), hd(adj.size()) {
		heavy_light(adj, root), decompose(adj, root, root);
	}
	int parent(int v) { return pa[v]; }
	int size(int v) { return sz[v]; }
	int depth(int v) { return dep[v]; }
	int heavy(int v) { return hv[v]; }
	int head(int v) { return hd[v]; }
};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	HLD hld{adj, 0};

	vector<array<int, 2>> ans(n);
	vector<array<int, 3>> qu{};
	qu.push_back({0, 1, 1000000});
	for (int y{1}; y <= 20; ++y) {
		vector<array<int, 3>> nq{};
		for (auto& [u, l, r] : qu) {
			int x{l};
			while (u != -1) {
				for (auto& v : adj[u]) {
					if (v == hld.parent(u) || v == hld.heavy(u)) continue;
					nq.push_back({v, -1, -1});
				}
				ans[u] = {x++, y};
				u = hld.heavy(u);
			}
		}
		int l{1}, r{1000000}, tot{}, cnt{};
		for (auto& [v, sl, sr] : nq) tot += hld.size(v);
		for (auto& [v, sl, sr] : nq) {
			sl = l + (r - l) / tot * cnt;
			cnt += hld.size(v);
			sr = l + (r - l) / tot * cnt - 1;
		}
		qu = nq;
	}

	for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
