//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <utility>
#define fi first
#define se second
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

	ll calc(ll x) {
		ll a{x}, b{x + 1};
		(a % 2 ? b : a) /= 2;
		return MM(MC(a), MC(b));
	}
	ll lg(ll x) {
		return 63 - __builtin_clzll(x);
	}
	array<array<ll, 61>, 61> dp{[] {
		array<array<ll, 61>, 61> d;
		d[1][0] = 1;
		for (int i{2}; i <= 60; ++i) {
			d[i][0] = 1;
			for (int j{1}; j < i - 1; ++j) d[i][j] = MA(d[i - 1][j], d[i - 1][j - 1]);
			d[i][i - 1] = calc((1ll << i) - 1);
		}
		return d;
	}()};
	ll solver(ll n, ll d) {
		ll t{lg(n)};
		if (d >= t) return calc(n);
		if (d == 0) return 1;
		if (n == (1ll << t)) return dp[t][d];
		return MA(dp[t][d], solver(n - (1ll << t), d - 1));
	}

	void solve() {
		ll n, k;
		cin >> n >> k;

		cout << solver(n, k) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
