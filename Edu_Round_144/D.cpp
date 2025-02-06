//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve1() {
	int n, k; ll x;
	cin >> n >> k >> x;
	vector<ll> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	for (int i{1}; i <= n; ++i) v[i] -= x;

	ll ans{0};
	if (x >= 0) {
		for (int i{1}; i <= k; ++i) v[i] += 2 * x;

		vector<ll> ps(n + 1);
		for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + v[i];

		ll mn{0};
		for (int i{1}; i <= n; ++i) {
			mn = min(mn, ps[i]), ans = max(ans, ps[i] - mn);
			if (i + 1 - k >= 1) {
				for (int j{i + 1 - k}; j <= i; ++j) ps[j] -= 2 * x, mn = min(mn, ps[j]);
			}
		}
	} else {
		for (int i{n + 1 - k}; i <= n; ++i) v[i] += 2 * x;
		for (int k1{0}; k1 <= k; ++k1) {
			vector<ll> ps(n + 1);
			for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + v[i];

			ll mn{0};
			for (int i{1}; i <= n; ++i) mn = min(mn, ps[i]), ans = max(ans, ps[i] - mn);

			int k2{k - k1};
			if (k2) v[k1 + 1] += 2 * x, v[n + 1 - k2] -= 2 * x;
		}
	}

	cout << ans << '\n';
}

void solve2() {
	int n, k; ll x;
	cin >> n >> k >> x;
	vector<ll> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
	dp[0][0] = 0;
	for (int i{0}; i + 1 <= n; ++i)
		for (int j{0}; j <= min(i, k); ++j) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = max(dp[i + 1][j], max(0ll, dp[i][j]) + v[i + 1] - x);
			if (j + 1 <= k) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(0ll, dp[i][j]) + v[i + 1] + x);
		}

	ll ans{0};
	for (int i{1}; i <= n; ++i)
		for (int j{min(i, k)}; j >= max(0, k - (n - i)); --j) ans = max(ans, dp[i][j]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
