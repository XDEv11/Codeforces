//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace C {
	int n, m, k;
	vector<vector<int>> adj{};
	vector<bool> vis{};
	vector<int> et{};
	void dfs(int u) {
		vis[u] = true;
		et.push_back(u);
		for (auto& v : adj[u]) {
			if (vis[v]) continue;
			dfs(v);
			et.push_back(u);
		}
	}
	bool solve() {
		if (!(cin >> n >> m >> k)) return false;
		adj.assign(n, {});
		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vis.assign(n, false), et.clear();
		dfs(0);

		for (int i{0}, j{0}; i < k; ++i) {
			int m{(2 * n - 1) / k + (i < (2 * n - 1) % k)};
			cout << m << ' ';
			while (m--) cout << (et[j++] + 1) << ' ';
			cout << '\n';
		}
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (C::solve()) ;
}
