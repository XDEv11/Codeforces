//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{accumulate(v.begin(), v.end(), 0ll)};
		for (int _{0}; _ < 3; ++_) {
			vector<ll> dp(n + 1, accumulate(v.begin(), v.end(), 0ll));
			dp[0] = 0;
			for (int i{0}; i < n; ++i) {
				if (i + 1 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(v[i] - v[i + 1]));
				if (i + 2 < n) {
					auto [mn, mx]{minmax_element(v.begin() + i, v.begin() + i + 3)};
					dp[i + 3] = min(dp[i + 3], dp[i] + *mx - *mn);
				}
			}
			ans = min(ans, dp[n]);
			rotate(v.begin(), next(v.begin()), v.end());
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
