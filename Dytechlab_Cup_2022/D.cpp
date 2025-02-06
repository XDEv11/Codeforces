//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, long long>> edges(m);
	for (auto& [u, v, w] : edges) cin >> u >> v >> w, --u, --v;

	vector<vector<pair<int, long long>>> adj(n);
	for (auto& [u, v, w] : edges) {
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<vector<int>> d(n, vector<int>(n));
	vector<bool> vis(n);
	queue<int> qu{};
	for (int x{0}; x < n; ++x) {
		fill(vis.begin(), vis.end(), false);
		vis[x] = true, d[x][x] = 0, qu.push(x);
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto& [v, _] : adj[u]) {
				if (vis[v]) continue;
				vis[v] = true, d[x][v] = d[x][u] + 1, qu.push(v);
			}
		}
	}

	long long ans{numeric_limits<long long>::max()};
	for (auto& [u, v, w] : edges) {
		ans = min(ans, (min(d[0][u] + d[n - 1][v], d[0][v] + d[n - 1][u]) + 1) * w);
	}
	for (auto& [u, v, w] : edges)
		for (int x{0}; x < n; ++x) {
			ans = min(ans, (d[0][x] + d[n - 1][x] + min(d[x][u], d[x][v]) + 2) * w);
		}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
