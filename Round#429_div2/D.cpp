//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D {
	int n, m;
	vector<int> r{};
	vector<vector<pair<int, int>>> adj{};
	vector<bool> vis{}, usd{}, ck0{}, ck1{};
	void dfs1(int u = 0) {
		vis[u] = true;
		int c{}, d{};
		for (auto& [v, i] : adj[u]) {
			if (vis[v]) continue;
			usd[i] = true;
			dfs1(v);
			if (ck0[v] && ck1[v]) ++d;
			else if (ck1[v]) ++c;
		}
		if (r[u] == -1 || d) ck0[u] = ck1[u] = true;
		else if (r[u] == c % 2) ck0[u] = true;
		else ck1[u] = true;
	}
	void dfs2(int u = 0, int d = 0) {
		vis[u] = true;
		int c{}, x{-1};
		if (r[u] != -1) {
			for (auto& [v, i] : adj[u]) {
				if (vis[v] || !usd[i]) continue;
				if (ck0[v] && ck1[v]) x = v;
				else if (ck1[v]) ++c;
			}
			if ((r[u] + d) % 2 == c % 2) x = -1;
		}
		for (auto& [v, i] : adj[u]) {
			if (vis[v]) continue;
			if (v == x || (!ck0[v] && ck1[v])) dfs2(v, 1);
			else usd[i] = false, dfs2(v, 0);
		}
	}
	bool solve() {
		if (!(cin >> n >> m)) return false;
		r.resize(n);
		for (auto& x : r) cin >> x;
		adj.assign(n, {});
		for (int i{0}; i < m; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].emplace_back(v, i);
			adj[v].emplace_back(u, i);
		}

		vis.assign(n, false), usd.assign(m, false), ck0.assign(n, false), ck1.assign(n, false), dfs1(0);
		if (!ck0[0]) return cout << "-1\n", true;

		vis.assign(n, false), dfs2(0);

		cout << count(usd.begin(), usd.end(), true) << '\n';
		for (int i{0}; i < m; ++i) {
			if (!usd[i]) continue;
			cout << (i + 1) << '\n';
		}
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (D::solve()) ;
}
