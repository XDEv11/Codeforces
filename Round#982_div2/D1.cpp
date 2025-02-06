//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	ll IMP{numeric_limits<ll>::max()};
	void solve() {
		int n1, n2;
		cin >> n1 >> n2;
		vector<ll> a(n1), b(n2);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		vector<ll> pa(n1 + 1);
		for (int i{0}; i < n1; ++i) pa[i + 1] = pa[i] + a[i];

		vector<vector<ll>> dp(n1 + 1, vector<ll>(n2, IMP));
		dp[0][0] = 0;
		for (int i{0}; i < n1; ++i) {
			ll t{IMP};
			for (int j{0}; j < n2; ++j) {
				t = min(t, dp[i][j]);
				if (t == IMP) continue;

				int l{i - 1}, r{n1};
				while (r - l > 1) {
					int m{(l + r) / 2};
					if (pa[m + 1] - pa[i] <= b[j]) l = m;
					else r = m;
				}
				if (l == i - 1) continue;

				dp[l + 1][j] = min(dp[l + 1][j], t + n2 - (j + 1));
			}
		}

		ll ans{IMP};
		for (int j{0}; j < n2; ++j) ans = min(ans, dp[n1][j]);

		cout << (ans == IMP ? -1 : ans) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
