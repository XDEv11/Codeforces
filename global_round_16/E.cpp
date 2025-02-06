#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace E {
	vector<vector<int>> adj{};
	int bud, leaf;

	bool dfs(int u, int w = -1) {
		bool is_bud{true};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			if (!dfs(v, u)) is_bud = false;
		}
		if (adj[u].size() == 1) return ++leaf, true;
		else return bud += is_bud, false;
	}

	void solve() {
		bud = 0;
		leaf = 0;

		int n;
		cin >> n;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v), adj[v].push_back(u);
		}

		dfs(0);

		cout << bud << " " << leaf << endl; //
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) E::solve();

	return 0;
}
