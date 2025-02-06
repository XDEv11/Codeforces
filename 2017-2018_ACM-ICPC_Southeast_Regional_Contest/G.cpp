#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
namespace G {
	int n;
	vector<map<int, vector<int>>> adj{};
	vector<bool> vis{};
	vector<int> pa{};
	void dfs(int u, int w) {
		if (vis[u]) return ;
		vis[u] = true, pa[u] = w;
		for (auto& [c, t] : adj[u])
			for (auto& v : t) {
				if (v == w || vis[v]) continue;
				dfs(v, u);
			}
	}
	bool solve() {
		if (!(cin >> n)) return false;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v, t;
			cin >> u >> v >> t, --u, --v;
			adj[u][t].push_back(v);
			adj[v][t].push_back(u);
		}
	 
		vis.assign(n, false), pa.resize(n);
		for (int u{0}; u < n; ++u)
			for (auto& [c, t] : adj[u]) {
				if (t.size() == 1) continue;
				for (auto& v : t) {
					if (vis[v]) {
						if (pa[u] == v) return cout << "0\n", true;
						continue;
					}
					dfs(v, u);
				}
			}
	 
		cout << count(vis.begin(), vis.end(), false) << '\n';
		for (int v{0}; v < n; ++v) {
			if (vis[v]) continue;
			cout << v + 1 << '\n';
		}
		return true;
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	while (G::solve()) ;
}
