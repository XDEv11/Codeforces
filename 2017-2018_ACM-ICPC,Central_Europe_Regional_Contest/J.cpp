//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void dfs(vector<int>& sz, const vector<vector<int>>& adj, int u, int w = -1) {
	sz[u] = 1;
	for (auto& v : adj[u]) {
		if (v == w) continue;
		dfs(sz, adj, v, u);
		sz[u] += sz[v];
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> sz(n);
	dfs(sz, adj, 0);

	vector<int> cnt(n + 1);
	for (auto& x : sz)
		for (int k{1}; k * k <= x; ++k) {
			if (x % k) continue;
			++cnt[k];
			if (x / k != k) ++cnt[x / k];
		}

	vector<int> ans{};
	for (int k{2}; k <= n; ++k) {
		if (n % k) continue;
		if (cnt[n / k] == k) ans.push_back(k - 1);
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
