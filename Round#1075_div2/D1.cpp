//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>

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
		int n, d;
		cin >> n >> d;
		vector<char> v(n);
		for (auto& x : v) cin >> x;
		if (v[0] == '0' || v[n - 1] == '0') return void(cout << "-1\n");

		ll ans{1};
		for (int i{1}; i < n; ++i) {
			ll c{v[i] == '1' ? 2 : i};
			ans = MM(ans, c);
			d /= gcd(d, c);
			if (d == 1) return void(cout << "-1\n");
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
