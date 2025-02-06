//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{1000000007};
	const ll I2{PM - PM / 2};
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
	ll MAA(ll& a, ll b) { return a = MA(a, b); };
	ll MSA(ll& a, ll b) { return a = MS(a, b); };
	ll MMA(ll& a, ll b) { return a = MM(a, b); };
	ll MDA(ll& a, ll b) { return a = MD(a, b); };

	void solve() {
		int n, s, t;
		cin >> n >> s >> t, --s, --t;
		vector<ll> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		if (s > t) {
			s = n - 1 - s, t = n - 1 - t;
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
		}

		b[s] = a[s], b[t] = a[t];
		for (int i{1}; i < n; ++i) b[i] += b[i - 1];
		auto ss{[&b](int i, int j) {
			ll r{b[j]};
			if (i) r -= b[i - 1];
			return r;
		}};

		vector<ll> ds(n), dt(n), dp(n);
		ds[s] = 1, dt[t] = 1;
		if (t - s == 1) dp[s] = 1;

		ll ans{};
		for (int r{1}; 2 * r <= n; ++r) {
			for (int i{max({s, t - r, r - 1})}; i <= min({s + r - 1, t - 1, n - r - 1}); ++i) {
				bool fl{i - r >= 0 && ss(i - r + 1, i) >= a[i - r]};
				bool fr{ss(i - r + 1, i) >= ss(i + 1, i + r)};
				ll p{dp[i]}; dp[i] = 0;
				if (fl && fr) MMA(p, I2);
				if (fl) dp[i] = p;
				if (fr) MAA(ans, p);
			}
			for (int i{min(s + r - 1, t - 2)}; i >= max(s, r - 1); --i) {
				bool fl{i - r >= 0 && ss(i - r + 1, i) >= a[i - r]};
				bool fr{ss(i - r + 1, i) >= a[i + 1]};
				ll p{ds[i]}; ds[i] = 0;
				if (fl && fr) MMA(p, I2);
				if (fl) ds[i] = p;
				if (fr) {
					MAA(ds[i + 1], p);
					MAA(dp[i + 1], MM(p, dt[i + 2]));
				}
			}

			for (int i{max({s, t - r, r})}; i <= min({s + r, t - 1, n - r - 1}); ++i) {
				bool fr{i + r + 1 < n && ss(i + 1, i + r) >= a[i + r + 1]};
				bool fl{ss(i + 1, i + r) >= ss(i - r, i)};
				ll p{dp[i]}; dp[i] = 0;
				if (fl && fr) MMA(p, I2);
				if (fr) dp[i] = p;
				if (!fl && !fr) MAA(ans, p);
			}
			ll q{};
			for (int i{s + 2}; i <= min(t, n - r); ++i) {
				bool fr{i + r < n && ss(i, i + r - 1) >= a[i + r]};
				bool fl{ss(i, i + r - 1) >= a[i - 1]};
				ll p{dt[i]}; dt[i] = 0;
				if (fl && fr) MMA(p, I2);
				if (fr) dt[i] = p;
				if (fl) {
					MAA(dt[i - 1], p);
					MAA(dp[i - 2], MM(p, ds[i - 2]));
				}
				MAA(q, ds[i - 2]);
				if (!fl && !fr) MAA(ans, MM(p, q));
			}
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
