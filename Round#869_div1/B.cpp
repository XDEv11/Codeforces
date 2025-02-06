//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int w{0}; w < n; ++w) {
		if (adj[w].size() < 4) continue;
		queue<int> qu{};
		vector<int> pa(n, -1), fr(n);
		pa[w] = w;
		for (auto& u : adj[w]) qu.push(u), pa[u] = w, fr[u] = u;
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto v : adj[u]) {
				if (v == w) continue;
				if (pa[v] != -1) {
					if (fr[u] == fr[v]) continue;
					vector<pair<int, int>> ans{};
					ans.emplace_back(u, v);
					for (; pa[u] != w; u = pa[u]) ans.emplace_back(u, pa[u]);
					ans.emplace_back(u, w);
					for (; pa[v] != w; v = pa[v]) ans.emplace_back(v, pa[v]);
					ans.emplace_back(v, w);
					int t{2};
					for (auto x : adj[w]) {
						if (x == u || x == v) continue;
						ans.emplace_back(w, x);
						if (!--t) break;
					}
					cout << "YES\n";
					cout << ans.size() << '\n';
					for (auto& [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
					return ;
				}
				qu.push(v), pa[v] = u, fr[v] = fr[u];
			}
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
