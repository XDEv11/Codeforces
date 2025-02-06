//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll n, l, r;
		cin >> n >> l >> r;
		vector<ll> v(n + 1);
		for (ll i{1}; i <= n; ++i) cin >> v[i];

		if (n % 2 == 0) { // let n be odd
			ll x{};
			for (ll i{1}; i <= n / 2; ++i) x ^= v[i];
			v.push_back(x), ++n;
		}
		v.resize(n * 2 + 1); // precalculate to 2n
		v[n + 1] = 0;
		for (ll i{1}; i <= (n + 1) / 2; ++i) v[n + 1] ^= v[i];
		for (ll i{n + 2}; i <= n * 2; ++i) {
			if (i % 2 == 0) v[i] = v[i - 1] ^ v[i / 2];
			else v[i] = v[i - 1];
		}

		vector<ll> ps(n * 2 + 1); // prefix sum
		for (ll i{1}; i <= n * 2; ++i) ps[i] = ps[i - 1] + v[i];

		ll tot{};
		for (ll i{1}; i <= n; ++i) tot ^= v[i];
		auto calc{[&](ll i) {
			ll a{};
			while (i > n * 2) {
				a ^= tot;
				if ((i /= 2) % 2 == 1) return a;
			}
			a ^= v[i];
			return a;
		}};
		if (r <= n * 2) return cout << ps[r] - ps[l - 1] << '\n', []{}();

		vector<ll> pe(n * 2 + 1); // prefix sum (only even index)
		for (int i{1}; i <= n * 2; ++i) {
			pe[i] = pe[i - 1];
			if (i % 2 == 0) pe[i] += v[i];
		}

		ll ans{};
		if (l <= n * 2) ans += ps[n * 2] - ps[l - 1], l = n * 2 + 1;
		if (l % 2 == 1) ans += calc(l++); // let l even
		if (l > r) return cout << ans << '\n', []{}();
		if (r % 2 == 0) ans += calc(r--); // let r odd
		if (l > r) return cout << ans << '\n', []{}();

		ll a{};
		while (true) {
			l /= 2, r /= 2, a ^= tot;
			if (l % 2 == 1) ans += a * 2, ++l;
			if (l > r) return cout << ans << '\n', []{}();
			if (r % 2 == 1) ans += a * 2, --r;
			ans += a * (r - l); // only even indexes between [l:r] remain
			if (r <= n * 2) break;

			if (l <= n * 2) {
				if (a) ans += ((n - l / 2 + 1) - (pe[n * 2] - pe[l - 1])) * 2;
				else ans += (pe[n * 2] - pe[l - 1]) * 2;
				l = n * 2 + 2;
			}
		}
		if (a) ans += ((r / 2 - l / 2 + 1) - (pe[r] - pe[l - 1])) * 2;
		else ans += (pe[r] - pe[l - 1]) * 2;

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tot{1};
	cin >> tot;
	while (tot--) solve();
}
