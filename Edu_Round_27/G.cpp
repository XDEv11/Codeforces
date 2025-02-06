//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace G {
	int n;
	vector<vector<array<int, 2>>> adj{};
	vector<bool> vis{};
	vector<int> dis{};
	vector<int> vec{};
	void dfs(int u) {
		vis[u] = true;
		for (auto& [v, w] : adj[u]) {
			if (vis[v]) {
				int a{dis[u] ^ w ^ dis[v]};
				for (auto& b : vec) {
					bool f{false};
					for (int k{26}; k >= 0; --k) {
						if ((a >> k) & 1 || (b >> k) & 1) {
							if ((a >> k) & 1 && (b >> k) & 1) f = true;
							break;
						}
					}
					if (f) a ^= b;
				}
				if (a) {
					vec.push_back(a);
					for (int i{vec.size() - 1}; i - 1 >= 0 && vec[i] > vec[i - 1]; --i) swap(vec[i], vec[i - 1]);
				}
			} else dis[v] = dis[u] ^ w, dfs(v);
		}
	}
	bool solve() {
		int m;
		if (!(cin >> n >> m)) return false;
		adj.assign(n, {});
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w, --u, --v;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		vis.assign(n, false), dis.resize(n), vec.clear();
		dfs(0);
		int a{dis[n - 1]};
		for (auto& b : vec) {
			if ((a ^ b) < a) a ^= b;
		}

		cout << a << '\n';
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (G::solve()) ;
}
