//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	vector<vector<int>> adj{};
	vector<int> pa{};
	void dfs(int u, int w = -1) {
		pa[u] = w;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			dfs(v, u);
		}
	}
	void solve() {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (auto& x : a) cin >> x;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pa.resize(n), dfs(0);

		vector<int> bc(n);
		for (int u{0}; u < n; ++u)
			for (auto& v : adj[u]) {
				if (v == pa[u]) continue;
				bc[u] += (a[v] == 1);
			}

		int wb{}, b2{}, x2{}, bad{};
		auto add{[&](int v) {
			if (bc[v] == 2) ++b2, x2 ^= v;
			else if (bc[v] >= 3) ++bad;
		}};
		auto sub{[&](int v) {
			if (bc[v] == 2) --b2, x2 ^= v;
			else if (bc[v] >= 3) --bad;
		}};
		for (int v{0}; v < n; ++v) {
			if (a[v] == 1 && (v == 0 || a[pa[v]] == 0)) ++wb;
			add(v);
		}
		while (q--) {
			int v;
			cin >> v, --v;

			if (a[v] == 0) {
				a[v] = 1;
				if (v == 0 || a[pa[v]] == 0) ++wb;
				wb -= bc[v];
				if (v) sub(pa[v]), ++bc[pa[v]], add(pa[v]);
			} else if (a[v] == 1) {
				a[v] = 0;
				if (v == 0 || a[pa[v]] == 0) --wb;
				wb += bc[v];
				if (v) sub(pa[v]), --bc[pa[v]], add(pa[v]);
			}

			if (wb == 1 && b2 <= 1 && !bad) {
				if (!b2) cout << "Yes\n";
				else cout << (x2 == 0 || a[pa[x2]] == 0 ? "Yes\n" : "No\n");
			} else cout << "No\n";
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
