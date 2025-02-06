//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	int n;
	vector<int> pa{};
	vector<vector<int>> ch{};
	vector<int> q{};
	vector<int> mn{}, mx{}, sz{}, ok{};
	void dfs(int u = 0) {
		mn[u] = mx[u] = q[u];
		sz[u] = 1;
		ok[u] = 0;
		for (auto& v : ch[u]) {
			dfs(v);
			mn[u] = min(mn[u], mn[v]);
			mx[u] = max(mx[u], mx[v]);
			sz[u] += sz[v];
			ok[u] += ok[v];
		}
		if (mn[u] == q[u] && mx[u] == q[u] + sz[u] - 1) ++ok[u];
	}
	void update(int u) {
		mn[u] = mx[u] = q[u];
		ok[u] = 0;
		for (auto& v : ch[u]) {
			mn[u] = min(mn[u], mn[v]);
			mx[u] = max(mx[u], mx[v]);
			ok[u] += ok[v];
		}
		if (mn[u] == q[u] && mx[u] == q[u] + sz[u] - 1) ++ok[u];
		if (u) update(pa[u]);
	}
	void solve() {
		int m;
		cin >> n >> m;
		pa.resize(n);
		for (int v{1}; v < n; ++v) cin >> pa[v], --pa[v];
		vector<int> p(n);
		for (auto& x : p) cin >> x, --x;
		q.resize(n);
		for (int v{0}; v < n; ++v) q[p[v]] = v;

		ch.assign(n, {});
		for (int v{1}; v < n; ++v) ch[pa[v]].push_back(v);

		mn.resize(n), mx.resize(n), sz.resize(n), ok.resize(n);
		dfs();

		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;

			swap(p[u], p[v]);
			q[p[u]] = u, q[p[v]] = v;
			update(p[u]), update(p[v]);

			cout << (ok[0] == n ? "YES\n" : "NO\n");
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
