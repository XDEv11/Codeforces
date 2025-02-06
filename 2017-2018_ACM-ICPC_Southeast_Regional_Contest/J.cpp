#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <limits>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, k{1};
	if (!(cin >> n >> m)) return false;
	vector<pair<int, int>> a(n);
	for (auto& [x, y] : a) cin >> x >> y, k = max(k, (x + y - 1) / y);
	vector<vector<pair<int, int>>> adj(n);
	for (int i{0}; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	vector<vector<int>> dp(k, vector<int>(n, numeric_limits<int>::min()));
	dp[0][0] = a[0].fi;
	for (int i{0}; i < k; ++i) {
		for (int u{0}; u < n; ++u)
			for (auto& [v, w] : adj[u]) {
				if (!(i + w < k)) continue;
				dp[i + w][v] = max(dp[i + w][v], dp[i][u] + max(0, a[v].fi - (i + w) * a[v].se));
			}
	}

	int ans{};
	for (int i{0}; i < k; ++i)
		for (int v{0}; v < n; ++v) ans = max(ans, dp[i][v]);

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
