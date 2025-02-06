//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> adj(n);
	vector<int> ans(n - 1);
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
	}

	auto dfs{[&](int u, int w = -1, bool is2 = false) {
		auto dfs_aux{[&](int u, int w, bool is2, auto& dfs_ref) {
			if (adj[u].size() > 2) return false;
			if (w == -1) {
				if (adj[u].size() >= 1) {
					auto [v, i]{adj[u][0]};
					ans[i] = 2;
					if (!dfs_ref(v, u, true, dfs_ref)) return false;
				}
				if (adj[u].size() >= 2) {
					auto [v, i]{adj[u][1]};
					ans[i] = 3;
					if (!dfs_ref(v, u, false, dfs_ref)) return false;
				}
			} else {
				for (auto& [v, i] : adj[u]) {
					if (v == w) continue;	
					ans[i] = is2 ? 3 : 2;
					if (!dfs_ref(v, u, ans[i] == 2, dfs_ref)) return false;
				}
			}
			return true;
		}};
		return dfs_aux(u, w, is2, dfs_aux);
	}};
	if (!dfs(0)) cout << "-1\n"s;
	else {
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
