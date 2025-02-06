//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	using ll = long long;

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<ll> c(k), h(k);
	for (auto& x : v) cin >> x, --x;
	for (auto& x : c) cin >> x;
	for (auto& x : h) cin >> x;

	vector<vector<ll>> dp(n, vector<ll>(k, numeric_limits<ll>::max()));
	vector<int> last(k, -1);
	dp[0][v[0]] = c[v[0]], last[v[0]] = 0;
	for (int i{1}; i < n; ++i) {
		for (int j{0}; j < k; ++j) {
			if (last[j] == -1) continue;
			// replace j
			dp[i][v[i - 1]] = min(dp[i][v[i - 1]], dp[i - 1][j] + (v[i] == j ? h[v[i]] : c[v[i]]));
			dp[i][v[i]] = min(dp[i][v[i]], dp[i - 1][j] + (v[i] == j ? h[v[i]] : c[v[i]]));
			// replace v[i - 1]
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + (v[i] == v[i - 1] ? h[v[i]] : c[v[i]]));
			dp[i][v[i]] = min(dp[i][v[i]], dp[i - 1][j] + (v[i] == v[i - 1] ? h[v[i]] : c[v[i]]));
		}
		last[v[i]] = i;
	}

	ll ans{numeric_limits<ll>::max()};
	for (int j{0}; j < k; ++j) ans = min(ans, dp[n - 1][j]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
