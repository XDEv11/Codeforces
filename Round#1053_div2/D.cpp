//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

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
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int c{};
		for (int i{0}; i < n; ++i) {
			if (i < n / 2) {
				if (v[i] > (n - 2 * i)) return cout << "0\n", []{}();
				c += v[i];
				if (c < 2 * (i + 1)) return cout << "0\n", []{}();
			} else if (n % 2 && i == n / 2) {
				if (v[i] > 1) return cout << "0\n", []{}();
				c += v[i];
			} else {
				if (v[i] != 0) return cout << "0\n", []{}();
			}
		}
		if (c != n) return cout << "0\n", []{}();

		vector<ll> fac(n + 1);
		fac[0] = 1;
		for (ll i{1}; i <= n; ++i) fac[i] = MM(fac[i - 1], i);

		c = 0;
		ll ans{1};
		for (int i{n - 1}; i >= 0; --i) {
			if (i < n / 2) {
				c += 2;
				ans = MM(ans, MD(fac[c], MM(fac[v[i]], fac[c - v[i]])));
				c -= v[i];
			} else if (n % 2 && i == n / 2) c += 1 - v[i];
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
