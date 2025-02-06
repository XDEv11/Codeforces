//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

namespace {
	int n, s, t;
	vector<vector<int>> adj{};
	vector<int> d{};
	void dfs(int u = t, int w = -1) {
		d[u] = (w != -1 ? d[w] + 1 : 0);
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
	}
	void solve() {
		cin >> n >> s >> t, --s, --t;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		d.resize(n), dfs();

		vector<pair<int, int>> a{};
		for (int v{0}; v < n; ++v) a.emplace_back(d[v], v);
		sort(a.rbegin(), a.rend());

		for (auto& [_, v] : a) cout << (v + 1) << ' ';
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
