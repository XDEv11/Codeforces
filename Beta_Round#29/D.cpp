//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;


namespace D {
	int n;
	vector<vector<int>> adj{};
	vector<int> od{}, rk{};
	int m;
	vector<int> a{};
	void dfs1(int u, int w = -1) {
		a[u] = u;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs1(v, u);
			a[u] = a[v];
		}
		m += (a[u] == u);
	}
	vector<int> ans{};
	void dfs2(int u, int w = -1) {
		ans.push_back(u);
		vector<pair<int, int>> tmp{};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			tmp.emplace_back(rk[a[v]], v);
		}
		sort(tmp.begin(), tmp.end());
		for (auto& [_, v] : tmp) {
			dfs2(v, u);
			ans.push_back(u);
		}
	}
	bool solve() {
		if (!(cin >> n)) return false;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		m = 0, a.resize(n), dfs1(0);

		od.resize(m);
		for (auto& v : od) cin >> v, --v;
		rk.resize(n);
		for (int i{0}; i < m; ++i) rk[od[i]] = i;

		ans.clear(), dfs2(0);
		int k{0};
		for (auto& v : ans) {
			if (k < m && v == od[k]) ++k;
		}
		if (k != m) return cout << "-1\n", true;

		for (auto& v : ans) cout << (v + 1) << ' ';
		cout << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (D::solve()) ;
}
