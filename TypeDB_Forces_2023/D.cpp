//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D {
	vector<int> adj{};
	vector<int> vis{};
	vector<bool> inf{};

	vector<vector<int>> iadj{};
	vector<int> cnt{};
	void dfs1(int u) {
		inf[u] = false;
		vis[u] = 1;
		if (adj[u] != -1) {
			int v{adj[u]};
			if (vis[v] == 0) {
				dfs1(v);
				inf[u] = inf[v];
			} else if (vis[v] == 1) {
				inf[u] = true;
			} else if (vis[v] == 2) {
				inf[u] = inf[v];
			}
		}
		vis[u] = 2;
	}
	void dfs2(int u) {
		vis[u] = 2;
		int s{1};
		for (auto& v : iadj[u]) {
			if (vis[v] == 0) dfs2(v);
			s += cnt[v];
		}
		cnt[u] = s;
	}
	void solve() {
		int n;
		cin >> n;
		adj.assign(n, -1);
		iadj.assign(n, {});
		for (int u{0}; u < n; ++u) {
			int x;
			cin >> x;

			int v{u + x};
			if (!(0 <= v && v < n)) continue;
			adj[u] = v;
			iadj[v].push_back(u);
		}

		vis.assign(n, 0), inf.resize(n);
		for (int u{0}; u < n; ++u) {
			if (vis[u] == 0) dfs1(u);
		}

		vis.assign(n, 0), cnt.resize(n);
		for (int u{0}; u < n; ++u) {
			if (vis[u] == 0) dfs2(u);
		}

		long long ans{0};
		int x{0}, c{0}, s{count(inf.begin(), inf.end(), true)};
		vis.assign(n, 0);
		while (vis[x] == 0) {
			vis[x] = 1;
			++c;
			ans += (2 * n + 1 - s - !inf[0] * cnt[x]);
			if (adj[x] == -1) break;
			x = adj[x];
		}
		if (!inf[0]) ans += static_cast<long long>(n - c) * (2 * n + 1);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D::solve();
}
