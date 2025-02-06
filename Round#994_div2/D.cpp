//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n, m; ll c;
		cin >> n >> m >> c;
		vector<vector<ll>> t(n, vector<ll>(m));
		ll imp{};
		for (auto& v : t)
			for (auto& x : v) cin >> x, imp += x;


		vector<vector<ll>> dp(n + 1, vector<ll>(m, imp));
		dp[n][m - 1] = 0;
		for (int i{n - 1}; i >= 0; --i)
			for (int j{0}; j < m; ++j)
				for (int u{0}; u < m; ++u) {
					ll s{u * c};
					for (int k{j}; k < m; ++k) {
						s += t[i][(k + u) % m];
						dp[i][j] = min(dp[i][j], s + dp[i + 1][k]);
					}
				}

		cout << dp[0][0] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
