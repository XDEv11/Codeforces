//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <queue>
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

	using pii = pair<int, int>;
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<pii> v(m);
		for (auto& [x, y] : v) cin >> x >> y, --x, --y;

		vector<int> t(n + 1);
		for (auto& [x, y] : v) t[y] = max(t[y], x + 1);

		vector<ll> dp(n + 1);
		dp[0] = 2;
		ll s{2}, j{0};
		for (int i{1}; i <= n; ++i) {
			s = MA(s, dp[i] = s);
			while (t[i] > j) s = MS(s, dp[j++]);
		}

		cout << dp[n] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int r{1};
	cin >> r;
	while (r--) solve();
}
