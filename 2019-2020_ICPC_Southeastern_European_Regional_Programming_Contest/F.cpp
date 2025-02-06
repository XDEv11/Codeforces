//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace F {
	vector<vector<int>> adj{};
	int dfs(int u, int w = -1) {
		int c{};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			c += dfs(v, u);
		}
		return c ? c - 1 : 1;
	}
	bool solve() {
		int n;
		if (!(cin >> n)) return false;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		return cout << (dfs(0) ? "Alice\n" : "Bob\n"), true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (F::solve()) ;
}
