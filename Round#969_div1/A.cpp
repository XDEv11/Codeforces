//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
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
		vector<char> a(n);
		for (auto& x : a) cin >> x;

		int c0{}, c1{}, cq{}, cc{};
		for (int v{1}; v < n; ++v) {
			if (adj[v].size() > 1) {
				if (a[v] == '?') ++cc;
			} else {
				if (a[v] == '0') ++c0;
				else if (a[v] == '1') ++c1;
				else if (a[v] == '?') ++cq;
			}
		}

		int ans;
		if (a[0] == '?') {
			if (c0 == c1 && (cc & 1)) ans = c0 + (cq + 1) / 2;
			else ans = max(c0, c1) + cq / 2;
		} else if (a[0] == '0') ans = c1 + (cq + 1) / 2;
		else if (a[0] == '1') ans = c0 + (cq + 1) / 2;

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
