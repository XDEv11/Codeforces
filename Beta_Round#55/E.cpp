//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, k;
	if (!(cin >> n >> m >> k)) return false;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	set<array<int, 3>> f{};
	while (k--) {
		int w, u, v;
		cin >> w >> u >> v, --w, --u, --v;
		f.insert({w, u, v});
	}

	vector<vector<int>> vis(n, vector<int>(n, -1));
	queue<array<int, 2>> qu{};
	qu.push({0, 0});
	while (!qu.empty()) {
		auto [w, u]{qu.front()}; qu.pop();
		for (auto& v : adj[u]) {
			if (vis[u][v] != -1 || f.count({w, u, v})) continue;
			if (v == n - 1) {
				vector<int> ans{};
				ans.push_back(n - 1);
				for (int x{w * n + u}; x; x = vis[x / n][x % n]) ans.push_back(x % n);
				ans.push_back(0);
				reverse(ans.begin(), ans.end());

				cout << ans.size() - 1 << '\n';
				for (auto& x : ans) cout << x + 1 << ' ';
				return cout << '\n', true;
			}
			vis[u][v] = w * n + u, qu.push({u, v});
		}
	}
	return cout << "-1\n", true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
