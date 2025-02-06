//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const vector<vector<double>> tb{[] {
	vector<vector<double>> dp(5001);
	dp[1] = {1.}, dp[2] = {0.5, 0.};
	for (int i{3}; i <= 5000; ++i) {
		dp[i].assign(i, 0.);
		dp[i][0] = 1. / i;
		for (int j{1}; j < i; ++j) {
			if (j != i - 1) dp[i][j] += dp[i - 2][j - 1] * (i - (j + 1)) / i;
			if (j != 1) dp[i][j] += dp[i - 2][j - 2] * (j + 1 - 2) / i;
		}
	}
	return dp;
}()};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
	}

	vector<double> ans(n);
	ans[n - 1] = 1;
	for (int u{n - 2}; u >= 0; --u) {
		vector<double> t{};
		for (auto& v : adj[u]) t.push_back(ans[v]);
		sort(t.rbegin(), t.rend());
		for (int i{0}; i < t.size(); ++i) ans[u] += t[i] * tb[t.size()][i];
	}

	cout << ans[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(10);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
