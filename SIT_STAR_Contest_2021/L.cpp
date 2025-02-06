#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> k{};
vector<vector<int>> adj{};

void dfs(int u, int w = -1) {
	for (auto& v : adj[u])
		if (v != w) {
			++k[u][v];
			dfs(v, u);
		}
}

void solve() {
	int n;
	cin >> n;

	adj.assign(n, {});
	vector<vector<int>> w(n, vector<int>(n, 0));
	k = w;

	for (int i{0}; i < n - 1; ++i) {
		int u, v, _w;
		cin >> u >> v >> _w, --u, --v;
		w[u][v] = w[v][u] = _w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int u{0}; u < n; ++u) dfs(u);

	long long _ans{0};
	for (int u{0}; u < n; ++u)
		for (int v{0}; v < n; ++v)
			_ans += static_cast<long long>(k[u][v]) * w[u][v];

	int m;
	cin >> m;
	while (m--) {
		int u, v, _w;
		cin >> u >> v >> _w, --u, --v;

		cout << _ans - static_cast<long long>(k[u][v]) * w[u][v] - static_cast<long long>(k[v][u]) * w[v][u]
			+ static_cast<long long>(k[u][v]) * _w + static_cast<long long>(k[u][v]) * _w << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
