//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	vector<vector<int>> adj{};
	vector<int> p{}, d{};
	void dfs(int u, int w = -1) {
		p[u] = w;
		d[u] = (w != -1 ? d[w] + 1 : 0);
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		p.resize(n), d.resize(n), dfs(0);

		vector<int> a{};
		vector<bool> c(n);
		for (int v{n - 1}; v != -1; v = p[v]) a.push_back(v), c[v] = true;
		reverse(a.begin(), a.end());

		vector<vector<int>> t(n);
		for (int v{0}; v < n; ++v) {
			if (c[v]) continue;
			t[d[v]].push_back(v);
		}

		vector<pair<int, int>> ans{};
		int eo{};
		for (int i{n - 1}; i >= 0; --i)
			for (auto& v : t[i]) {
				ans.emplace_back(1, 0), eo ^= 1;
				if ((i & 1) == (eo & 1)) ans.emplace_back(1, 0), eo ^= 1;
				ans.emplace_back(2, v);
			}
		for (int i{0}; i < a.size() - 1; ++i) {
			auto& v{a[i]};
			ans.emplace_back(1, 0), eo ^= 1;
			if ((d[v] & 1) == (eo & 1)) ans.emplace_back(1, 0), eo ^= 1;
			ans.emplace_back(2, v);
		}

		cout << ans.size() << '\n';
		for (auto& [x, y] : ans) {
			if (x == 1) cout << "1\n";
			else cout << "2 " << (y + 1) << '\n';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
