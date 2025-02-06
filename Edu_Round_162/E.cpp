//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace E {
	int n;
	vector<vector<int>> adj{};
	vector<int> c{};

	long long ans{};
	vector<int> cnt{};
	void dfs(int u, int w = -1) {
		int x{cnt[c[u]]};
		ans += x;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			cnt[c[u]] = 1;
			dfs(v, u);
		}
		cnt[c[u]] = x + 1;
	}
	void solve() {
		cin >> n;
		c.resize(n), adj.assign(n, {});
		for (auto& x : c) cin >> x;
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ans = 0, cnt.assign(n + 1, 0), dfs(0);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) E::solve();
}
