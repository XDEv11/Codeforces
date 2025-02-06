//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{1000000007};
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
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for (auto& x : v) cin >> x;

		for (int i{1}; i <= n; ++i) {
			if (v[i] != -1 && v[i] != 0 && v[i] != i) {
				int j{v[i]};
				if (clamp(j, 1, n) != j) return cout << "0\n", []{}();
				if (v[j] == -1) v[j] = i;
				if (v[j] != i) return cout << "0\n", []{}();
			}
		}

		int c{count(v.begin(), v.end(), -1) - 1};
		vector<ll> dp(c + 1);
		dp[0] = 1;
		for (int i{0}; i < c; ++i) {
			dp[i + 1] = MM(dp[i], 2);
			if (i) dp[i + 1] = MA(dp[i + 1], MM(dp[i - 1], i));
		}

		ll ans{dp[c]};
		if (v[n] == -1) ans = MS(ans, dp[c - 1]);

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
