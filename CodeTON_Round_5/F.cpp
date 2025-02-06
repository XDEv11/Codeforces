//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int _{0}; _ < n - 1; ++_) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v), adj[v].push_back(u);
	}

	vector<ll> ans(n + 1, numeric_limits<ll>::max());
	ans[0] = 0;
	for (int r{0}; r < n; ++r) {
		queue<int> qu{};
		vector<int> d(n);
		d[r] = 1, qu.push(r);
		ll cnt{};
		for (int i{1}; i <= n; ++i) {
			auto u{qu.front()}; qu.pop();
			cnt += d[u] - 1;
			ans[i] = min(ans[i], cnt);
			for (auto& v : adj[u]) {
				if (d[v]) continue;
				d[v] = d[u] + 1, qu.push(v);
			}
		}
	}

	for (int i{0}; i <= n; ++i) cout << (ll(n - 1) * i - 2 * ans[i]) << " \n"[i == n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
