//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D {
	static int n;
	static vector<vector<int>> adj{};
	static vector<int> pa{}, dep{};
	static void _dfs(int u, int w = -1, int d = 0) {
		pa[u] = w, dep[u] = d;
		for (auto& v : adj[u]) {
			if (v == w) continue;
			_dfs(v, u, d + 1);
		}
	}
	static void dfs(int u) {
		pa.resize(n), dep.resize(n), _dfs(u);
	}
	static void solve() {
		int a, b;
		cin >> n >> a >> b, --a, --b;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans{};

		dfs(a);
		int x{b}, y{b};
		while (x != a && pa[x] != a) x = pa[pa[x]], y = pa[y], ++ans;
		if (x != a) y = pa[y];

		dfs(y);
		ans += 2 * (n - 1) - *max_element(dep.begin(), dep.end());
		if (x != a) ++ans;

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D::solve();
}
