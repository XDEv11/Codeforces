//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

static void solve() {
	using ll = long long;
	auto maximize{[](ll& a, const ll& b) { a = max(a, b); }};

	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
	for (int i{0}; i < n; ++i) {
		for (int k{0}; k <= m; ++k) maximize(dp[i + 1][k], dp[i][k]);
		for (int u{1}; u <= m; ++u)
			for (int j{max(0, i - u)}; j <= i && j + u < n; ++j) {
				ll c{};
				for (int k{j}; k < j + u + 1; ++k) c += v[k] - v[i];
				for (int k{0}; k + u <= m; ++k) maximize(dp[j + u + 1][k + u], dp[j][k] + c);
			}
	}

	cout << (accumulate(v.begin(), v.end(), 0ll) - dp[n][m]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
