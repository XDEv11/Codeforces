//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace D {
	using ll = long long;
	const ll mod{1000000007};

	/* Iterative Function to calculate (a^b) % mod in O(log b) */
	long long power_mod(long long a, long long b) {
		long long res{1};
		while (b > 0) {
			if (b & 1) res = res * a % mod;
			b >>= 1;
			a = (a * a) % mod;
		}
		return res;
	}

	vector<vector<int>> adj{};
	vector<int> hei{};

	int dfs(int u, int w = -1) {
		int h{0};
		for (auto& v : adj[u]) {
			if (v == w) continue;
			h = max(h, dfs(v, u) + 1);
		}
		return hei[u] = h;
	}

	void solve() {
		int n;
		cin >> n;
		adj.assign(n, {});
		hei.resize(n);
		for (int i{0}; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0);

		ll ans{0}, p{power_mod(2, n - 1)};
		for (auto& h : hei) ans = (ans + p * (h + 1)) % mod;
	
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
