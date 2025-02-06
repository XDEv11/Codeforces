#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

bool solve() {
	int t;
	if (!(cin >> t)) return false;
	int n, m, c;
	cin >> n >> m >> c;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<pair<int, int>> a(n);
	for (auto& [x, y] : a) cin >> x >> y;

	vector<vector<int>> dp(t + 1, vector<int>(n, -1));
	dp[a[0].fi][0] = a[0].se;
	auto min_assign{[](int& x, int y) {
		if (x == -1 || x > y) x = y;
	}};
	for (int i{0}; i < t; ++i)
		for (int u{0}; u < n; ++u) {
			if (dp[i][u] == -1) continue;
			if (i + a[u].fi <= t) min_assign(dp[i + a[u].fi][u], dp[i][u] + a[u].se);
			for (auto& v : adj[u]) {
				if (i + c + a[v].fi <= t) min_assign(dp[i + c + a[v].fi][v], dp[i][u] + a[v].se);
			}
		}

	if (dp[t][0] != -1) cout << dp[t][0] << '\n';
	else cout << "It is a trap.\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
