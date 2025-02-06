//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>

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
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		map<int, ll> dp{};
		dp[0] = 1;
		for (int i{0}, p{}; i + 1 < n; ++i) {
			p ^= v[i];
			ll a{dp[p]}, b{dp[p ^ v[i + 1]]};
			dp[p] = MA(MM(a, 3), MM(b, 2));
		}

		ll ans{};
		for (auto& [x, c] : dp) ans = MA(ans, c);
		ans = MM(ans, 3);

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t; while (t--) solve(); }
