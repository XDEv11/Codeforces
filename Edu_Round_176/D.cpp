//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	template<typename T>
	using tensor = vector<matrix<T>>;
	using ll = long long;
	tensor<ll> dp{[] {
		tensor<ll> d(58, matrix<ll>(58, vector<ll>(58, (numeric_limits<ll>::max() >> 1))));
		dp[0][0][0] = 0;
		auto minimize{[](ll& a, ll b) { a = min(a, b); }};
		for (int i{1}; i <= 57; ++i)
			for (int j{0}; j <= 57; ++j)
				for (int k{0}; k <= 57; ++k) {
					minimize(d[i][j][k], d[i - 1][j][k]);
					if (j + i <= 57) minimize(d[i][j + i][k], d[i - 1][j][k] + (1ll << i));
					if (k + i <= 57) minimize(d[i][j][k + i], d[i - 1][j][k] + (1ll << i));
				}
		return d;
	}()};
	void solve() {
		ll x, y;
		cin >> x >> y;

		ll ans{numeric_limits<ll>::max()};
		for (int j{0}; j <= 57; ++j)
			for (int k{0}; k <= 57; ++k) {
				if ((x >> j) != (y >> k)) continue;
				ans = min(ans, dp[57][j][k]);
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
