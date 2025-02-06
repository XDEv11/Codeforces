//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hopcroft & Tarjan
class HopcroftTarjan {
	vector<int> dep, low;
	void dfs(const vector<vector<int>>& adj, vector<bool>& ap, int u, int w = -1, int d = 1) {
		int child{0};
		low[u] = dep[u] = d;
		for (auto& v : adj[u]) {
			if (v == w || dep[v] >= dep[u]) continue;
			if (!dep[v]) { // tree edge
				++child, dfs(adj, ap, v, u, d + 1);
				low[u] = min(low[u], low[v]);
				if (low[v] >= dep[u]) ap[u] = true;
			} else low[u] = min(low[u], dep[v]); // back edge
		}
		if (w == -1) ap[u] = (child > 1);
	}
public:
	vector<bool> operator()(const vector<vector<int>>& adj) {
		int n{adj.size()};
		dep.assign(n, 0), low.resize(n);
		vector<bool> ap(n, false);
		for (int v{0}; v < n; ++v) {
			if (!dep[v]) dfs(adj, ap, v);
		}
		return ap;
	}
};

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	int c{};
	vector<vector<int>> g(n + 2, vector<int>(m + 2, -1));
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) {
			char x; cin >> x;
			if (x == '#') g[i][j] = c++;
		}
	if (c <= 2) return cout << "-1\n", true;

	vector<vector<int>> adj(c);
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) {
			if (g[i][j] == -1) continue;
			int u{g[i][j]}, v{g[i + 1][j]}, w{g[i][j + 1]};
			if (v != -1) adj[u].push_back(v), adj[v].push_back(u);
			if (w != -1) adj[u].push_back(w), adj[w].push_back(u);
		}

	auto ap{HopcroftTarjan{}(adj)};
	cout << (count(ap.begin(), ap.end(), true) ? 1 : 2) << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
