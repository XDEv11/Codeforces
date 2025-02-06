//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<set<int>> adj(n);
		while (m--) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].insert(v);
			adj[v].insert(u);
		}

		vector<array<int, 3>> ans{};

		for (int u{0}; u < n; ++u) {
			while (adj[u].size() >= 2) {
				auto v{*adj[u].begin()}; adj[u].erase(v), adj[v].erase(u);
				auto w{*adj[u].begin()}; adj[u].erase(w), adj[w].erase(u);
				ans.push_back({u, v, w});
				if (adj[v].count(w)) adj[v].erase(w), adj[w].erase(v);
				else adj[v].insert(w), adj[w].insert(v);
			}
		}
		for (int u{0}; u < n; ++u) {
			if (adj[u].empty()) continue;
			auto v{*adj[u].begin()};
			vector<bool> ck(n); ck[u] = ck[v] = true;
			for (int w{0}; w < n; ++w) {
				if (ck[w]) continue;
				ans.push_back({u, v, w}), ck[w] = true;
				if (!adj[w].empty()) ck[*adj[w].begin()] = true;
				v = w;
			}
			break;
		}


		cout << ans.size() << '\n';
		for (auto& [x, y, z] : ans) cout << (x + 1) << ' ' << (y + 1) << ' ' << (z + 1) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
