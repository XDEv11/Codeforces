//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> c(n + 1, vector<int>(n + 1));
	for (int i{1}; i <= n; ++i)
		for (int j{i}; j <= n; ++j) cin >> c[i][j];

	vector<int> c1(n + 1), c2(n + 1);
	for (int j{1}; j <= n; ++j) {
		c1[j] = j;
		for (int i{1}; i <= j; ++i) {
			if (c[i][j] != 1) continue;
			c1[j] = i;
			break;
		}
		for (int i{j}; i >= 1; --i) {
			if (c[i][j] != 2) continue;
			c2[j] = i;
			break;
		}
		if (c2[j] == j) return cout << "0\n", []{}();
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(n));
	dp[1][0] = 2;
	for (int i{2}; i <= n; ++i) {
		// same
		for (int j{c2[i]}; j < c1[i]; ++j) dp[i][j] = MA(dp[i][j], dp[i - 1][j]);
		if (c1[i] != i) continue;
		// different
		for (int j{0}; j < i - 1; ++j) dp[i][i - 1] = MA(dp[i][i - 1], dp[i - 1][j]);
	}

	ll ans{};
	for (int j{0}; j < n; ++j) ans = MA(ans, dp[n][j]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
