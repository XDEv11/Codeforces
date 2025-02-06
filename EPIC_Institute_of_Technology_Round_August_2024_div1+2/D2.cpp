//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace {
	// heavy-light decomposition
	class LCA {
		const vector<vector<int>>& adj;
		int n;
		vector<int> pa, dep, heavy, head;
		int heavy_light(int u, int w = -1, int d = 0) {
			pa[u] = w, dep[u] = d;
			int mx{0}, tot{1};
			for (auto& v : adj[u]) {
				if (v == w) continue;
				int sz{heavy_light(v, u, d + 1)};
				if (sz > mx) mx = sz, heavy[u] = v;
				tot += sz;
			}
			return tot;
		}
		void decompose(int u, int h) {
			head[u] = h;
			for (auto& v : adj[u]) {
				if (v == pa[u]) continue;
				if (v == heavy[u]) decompose(v, h);
				else decompose(v, v);
			}
		}
	public:
		LCA(const vector<vector<int>>& _adj, int root) : adj{_adj}, n{adj.size()}, pa(n), dep(n), heavy(n), head(n) {
			// Heavy-Light Decomposition
			heavy_light(root);
			decompose(root, root);
		}
		int operator()(int u, int v) {
			while (head[u] != head[v]) {
				if (dep[head[u]] <= dep[head[v]]) v = pa[head[v]];
				else u = pa[head[u]];
			}
			return dep[u] <= dep[v] ? u : v;
		}
	};
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> pa(n);
		for (int v{1}; v < n; ++v) cin >> pa[v], --pa[v];
		vector<vector<int>> adj(n);
		for (int v{1}; v < n; ++v) {
			auto& u{pa[v]};
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> od(n);
		for (auto& x : od) cin >> x, --x;

		LCA lca{adj, 0};
		auto check{[&pa, &od, &lca](int i) {
			if (i) {
				if (od[i]) {
					auto& p{pa[od[i]]};
					return lca(p, od[i - 1]) == p;
				} else return false;
			} else return od[i] == 0;
		}};

		int cnt{};
		for (int i{0}; i < n; ++i) cnt += check(i);
		while (m--) {
			int x, y;
			cin >> x >> y, --x, --y;
			if (x > y) swap(x, y);

			cnt -= check(x);
			if (x + 1 != y) cnt -= check(x + 1);
			cnt -= check(y);
			if (y + 1 < n) cnt -= check(y + 1);

			swap(od[x], od[y]);

			cnt += check(x);
			if (x + 1 != y) cnt += check(x + 1);
			cnt += check(y);
			if (y + 1 < n) cnt += check(y + 1);

			cout << (cnt == n ? "YES\n" : "NO\n");
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
