//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{1000000007};
	ll MC(ll v) { return (v % PM + PM) % PM; }
	ll MA(ll v, ll p) { return (v + p) % PM; }
	ll MS(ll v, ll p) { return (v - p + PM) % PM; }
	ll MM(ll v, ll p) { return (v * p) % PM; }
	ll MP(ll v, ll p) {
		ll res{1};
		do {
			if (p & 1) res = MM(res, v);
		} while (v = MM(v, v), p >>= 1);
		return res;
	}
	ll MI(ll v) { return MP(v, PM - 2); }
	ll MD(ll v, ll p) { return MM(v, MI(p)); }
	const ll L{1000000000};
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll s{};
		vector<pair<ll, int>> stk{};
		for (int i{0}; i < n; ++i) {
			int p{};
			while (v[i] % 2 == 0) v[i] /= 2, ++p;
			while (!stk.empty()) {
				auto& [x, y]{stk.back()};
				if (p >= 30 || x <= (v[i] << p)) {
					s += x, p += y;
					stk.pop_back();
				} else break;
			}
			if (p) stk.emplace_back(v[i], p);
			else s += v[i];

			ll ans{MC(s)};
			for (auto& [x, y] : stk) ans = MA(ans, MM(x, MP(2, y)));

			cout << ans << ' ';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
