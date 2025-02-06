//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<vector<int>> adj(n);
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int cnl{0};
		for (int v{0}; v < n; ++v) cnl += (adj[v].size() != 1);
		ll ans{ll(n - cnl) *  cnl};
		
		int cnn{0};
		for (int u{0}; u < n; ++u) {
			if (adj[u].size() == 1) continue;
			bool f{true};
			for (auto& v : adj[u]) f = (f && adj[v].size() != 1);
			cnn += f;
		}

		for (int u{0}; u < n; ++u) {
			if (adj[u].size() == 1) continue;
			int c{};
			for (auto& v : adj[u]) c += (adj[v].size() != 1);
			if (c == adj[u].size()) continue;
			ans += cnn * ll(c - 1);
		}

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
