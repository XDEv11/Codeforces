//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace {
	int n, m, s;
	vector<basic_string<int>> adj{};
	int dfs(int u, int w = -1) {
		int mn{-1};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			auto h{dfs(v, u)};
			if (mn != -1) {
				if (h + mn < m) return 0;
				mn = min(mn, h);
			} else mn = h;
		}
		return mn + 1;
	}
	void solve() {
		cin >> n >> m >> s, --s;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cout << (dfs(s) ? "NO\n" : "YES\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
