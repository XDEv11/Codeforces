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

	bool solve() {
		int n, q;
		if (!(cin >> n)) return false;
		cin >> q;
		array<int, 61> cnt{};
		for (int _{0}; _ < n; ++_) {
			int x;
			cin >> x;
			++cnt[x];
		}

		while (q--) {
			int op; ll x;
			cin >> op >> x;
			if (op == 3) {
				ll ans{}, a{1};

				int i{60}, k{60}, m{n};
				while (true) {
					while (i >= 0 && !(x & (1ll << i))) {
						m -= cnt[k];
						ans = MA(ans, MM(MM(a, MS(MP(2, cnt[k]), 1)), MP(2, m)));
						--i, --k;
					}
					if (i < 0) break;

					int j{i};
					while (j >= 0 && (x & (1ll << j))) --j;
					if (i - j > cnt[k]) { a = 0; break; }
					m -= cnt[k];

					ll t{MP(2, cnt[k])}, b{1}; // C(cnt[k], i - j)
					t = MS(t, b);
					for (int f{1}; f <= i - j; ++f) {
						b = MD(MM(b, cnt[k] - (f - 1)), f);
						t = MS(t, b);
					}
					ans = MA(ans, MM(MM(a, t), MP(2, m)));
					a = MM(a, b);

					i = j - 1, --k;
				}
				ans = MA(ans, MM(a, MP(2, m)));

				cout << ans << '\n';
			} else if (op == 2) --n, --cnt[x];
			else if (op == 1) ++n, ++cnt[x];
		}
		return !!cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
