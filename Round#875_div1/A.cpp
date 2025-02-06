//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

int dfs(const vector<vector<pair<int, int>>>& adj, int u, int ui = 0) {
	int mx{1};
	for (auto& [v, vi] : adj[u]) {
		if (ui == vi) continue;
		mx = max(mx, dfs(adj, v, vi) + (vi < ui));
	}
	return mx;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> adj(n);
	for (int i{1}; i < n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	cout << dfs(adj, 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
