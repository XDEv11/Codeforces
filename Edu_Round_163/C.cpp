//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int m;
	cin >> m;
	vector<vector<char>> g(2, vector<char>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	vector<vector<int>> adj(2 * m);
	for (int j{0}; j < m; ++j) {
		if (j - 1 >= 0 && g[0][j - 1] == '<') adj[j].push_back(j - 2);
		if (j + 1 < m && g[0][j + 1] == '>') adj[j].push_back(j + 2);
		adj[j].push_back(m + j + (g[1][j] == '>' ? 1 : -1));
	}
	for (int j{0}; j < m; ++j) {
		if (j - 1 >= 0 && g[1][j - 1] == '<') adj[m + j].push_back(m + j - 2);
		if (j + 1 < m && g[1][j + 1] == '>') adj[m + j].push_back(m + j + 2);
		adj[m + j].push_back(j + (g[0][j] == '>' ? 1 : -1));
	}

	vector<bool> vis(2 * m);
	queue<int> qu{};
	vis[0] = true, qu.push(0);
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();
		for (auto& v : adj[u]) {
			if (!vis[v]) vis[v] = true, qu.push(v);
		}
	}

	cout << (vis[m + m - 1] ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
