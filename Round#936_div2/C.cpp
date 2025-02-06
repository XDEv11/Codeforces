//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace C {
	int n;
	vector<vector<int>> adj{};

	int th, cnt;
	int dfs(int u = 0, int w = -1) {
		int sz{1};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			sz += dfs(v, u);
		}
		if (sz >= th) return ++cnt, 0;
		else return sz;
	}
	void solve() {
		int k;
		cin >> n >> k;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int l{1}, r{n};
		while (r - l > 1) {
			int m{(l + r) / 2};
			th = m, cnt = 0, dfs();
			(cnt >= k + 1 ? l : r) = m;
		}
		cout << l << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) C::solve();
}
