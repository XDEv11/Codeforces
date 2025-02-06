//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	int n;
	vector<int> a{};
	vector<vector<int>> adj{};
	vector<int> pa{}, ti{}, to{};
	int t;
	void dfs(int u, int w = -1) {
		pa[u] = w;
		ti[u] = t++;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
		to[u] = t++;
	}
	void solve() {
		cin >> n;
		a.resize(n);
		for (auto& x : a) cin >> x;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), ti.resize(n), to.resize(n), t = 0, dfs(0);

		vector<int> mn(n + 2, numeric_limits<int>::max()), mx(n + 2);
		auto minimize{[](int& x, int y) { x = min(x, y); }};
		auto maximize{[](int& x, int y) { x = max(x, y); }};
		for (int v{0}; v < n; ++v) minimize(mn[a[v]], ti[v]), maximize(mx[a[v]], to[v]);
		for (int i{n - 1}; i >= 1; --i) minimize(mn[i], mn[i + 1]), maximize(mx[i], mx[i + 1]);

		int ans0{}, ans1{};
		for (int v{0}; v < n; ++v) {
			if (ti[v] < mn[a[v] + 1] && mx[a[v] + 1] < to[v]) continue;
			if (a[v] > ans0) ans0 = a[v], ans1 = v + 1;
		}

		cout << ans1 << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
