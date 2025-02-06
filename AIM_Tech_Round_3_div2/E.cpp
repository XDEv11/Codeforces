//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace E {
	int n;
	vector<vector<int>> adj{};
	vector<int> pa{}, sz{}, mx1{}, mx2{};
	void dfs1(int u, int w = -1) {
		pa[u] = w, sz[u] = 1, mx1[u] = 0;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs1(v, u);
			sz[u] += sz[v];
			mx1[u] = max(mx1[u], mx1[v]);
		}
		if (sz[u] <= n / 2) mx1[u] = sz[u];
	}
	void dfs2(int u, int s = 0) {
		mx2[u] = s;
		multiset<int> ms{};
		for (auto& v : adj[u]) {
			if (v == pa[u]) continue;
			ms.insert(mx1[v]);
		}
		for (auto& v : adj[u]) {
			if (v == pa[u]) continue;
			ms.erase(ms.find(mx1[v]));
			int x;
			if (n - sz[v] <= n / 2) x = n - sz[v];
			else x = max(mx2[u], ms.empty() ? 0 : *ms.rbegin());
			dfs2(v, x);
			ms.insert(mx1[v]);
		}
	}
	bool solve() {
		if (!(cin >> n)) return false;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), sz.resize(n), mx1.resize(n), mx2.resize(n);
		dfs1(0), dfs2(0);

		vector<bool> ans(n, true);
		for (int u{0}; u < n; ++u) {
			if (sz[u] > n / 2) {
				for (auto& v : adj[u]) {
					if (v == pa[u]) continue;
					if (sz[v] - mx1[v] > n / 2) ans[u] = false;
				}
			} else {
				if ((n - sz[u]) - mx2[u] > n / 2) ans[u] = false;
			}
		}

		for (int v{0}; v < n; ++v) cout << ans[v] << " \n"[v == n - 1];
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (E::solve()) ;
}
