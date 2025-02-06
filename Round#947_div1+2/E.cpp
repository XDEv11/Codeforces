//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D {
	static int n;
	static vector<vector<int>> adj{};
	static void solve() {
		int q;
		cin >> n >> q;
		vector<int> c(n);
		for (auto& x : c) cin >> x;
		adj.assign(n, {});
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		while (q--) {
			int x;
			cin >> x, --x;

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) D::solve();
}
