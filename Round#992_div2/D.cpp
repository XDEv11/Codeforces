//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

namespace {
	int n;
	vector<vector<int>> adj{};
	vector<int> a{};
	set<int> so{}, se{};
	void dfs(int u, int w = -1) {
		int f{-1};
		if (so.count(a[u] + 1) || se.count(a[u] + 1)) {
			so.erase(a[u] + 1), se.erase(a[u] + 1);
			f = a[u] + 1;
		}
		for (auto& v : adj[u]) {
			if (v == w) continue;
			if (f == -1) {
				if (a[u] & 1) {
					auto it{so.begin()};
					while (abs(a[u] - *it) == 2) ++it;
					a[v] = *it, so.erase(it);
				} else {
					auto it{se.begin()};
					while (abs(a[u] - *it) == 2) ++it;
					a[v] = *it, se.erase(it);
				}
			} else a[v] = f, f = -1;
			dfs(v, u);
		}
	}
	void solve() {
		cin >> n;
		adj.assign(n, {});
		a.resize(n);
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		so = {}, se = {};
		for (int i{3}; i <= 2 * n; i += 2) so.insert(i);
		for (int i{2}; i <= 2 * n; i += 2) se.insert(i);
		a[0] = 1, dfs(0);

		for (auto& x : a) cout << x << ' ';
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
