//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{998244353};
	ll MC(ll a) { return (a % PM + PM) % PM; }
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
	ll& MAA(ll& a, ll b) { return a = MA(a, b); }

	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		ll ans{};
		{ // ..(
			vector<array<ll, 2>> dp(n);
			for (int i{0}; i < n; ++i) dp[i][v[i] == '('] = 1;
			for (int i{0}; i + 1 < n; ++i) {
				MAA(dp[i + 1][0], dp[i][0]);
				MAA(dp[i + 1][1], dp[i][1]);
				MAA(dp[i + 1][v[i + 1] == '('], MA(dp[i][0], dp[i][1]));
			}
			MAA(ans, dp[n - 1][1]);
		}
		{ // ..)
			vector<int> pf(n);
			for (int i{0}; i < n; ++i) {
				if (i) pf[i] += pf[i - 1];
				pf[i] += (v[i] == '(' ? 1 : -1);
			}
			vector<array<ll, 2>> dp(n);
			for (int i{0}; i < n; ++i) dp[i][v[i] == '('] = 1;
			for (int i{0}; i + 1 < n; ++i) {
				if (pf[i] < 2) dp[i][1] = 0;
				MAA(dp[i + 1][0], dp[i][0]);
				MAA(dp[i + 1][1], dp[i][1]);
				MAA(dp[i + 1][v[i + 1] == '('], MA(dp[i][0], dp[i][1]));
			}
			MAA(ans, dp[n - 1][0]);
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
