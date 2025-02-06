//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace E {
	using ll = long long;
	const ll LB{0}, HB{1000000000000000000ll};
	int n;
	vector<vector<int>> adj{};
	vector<pair<ll, ll>> ans{};
	bool dfs(int u, int w = -1, ll lx = LB, ll rx = HB, ll ly = LB, ll ry = HB, int c = -1) {
		ll mx{(lx + rx) / 2}, my{(ly + ry) / 2};
		ans[u] = {mx, my};
		int d{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			if (d == c) ++d;
			if (d == 4) return false;
			bool r;
			switch (d) {
				break; case 0: r = dfs(v, u, (mx + rx + 1) / 2, rx, (ly + my + 1) / 2, (my + ry) / 2, 2);
				break; case 1: r = dfs(v, u, (lx + mx + 1) / 2, (mx + rx) / 2, (my + ry + 1) / 2, ry, 3);
				break; case 2: r = dfs(v, u, lx, (lx + mx) / 2, (ly + my + 1) / 2, (my + ry) / 2, 0);
				break; case 3: r = dfs(v, u, (lx + mx + 1) / 2, (mx + rx) / 2, ly, (my + ry) / 2, 1);
			}
			if (!r) return false;
			++d;
		}
		return true;
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

		ans.resize(n);
		if (!dfs(0)) return cout << "NO\n", true;
		cout << "YES\n";
		for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (E::solve()) ;
}
