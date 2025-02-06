//#pragma GCC optimize ("O3")

#include <iostream>
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

	// segment tree
	template<typename value_t, class merge_t>
	class SGT {
		int n;
		vector<value_t> t; // root starts at 1
		value_t defa;
		merge_t merge; // associative function for SGT
	public:
		explicit SGT(int _n, value_t _defa, const merge_t& _merge = merge_t{})
			: n{_n}, t(2 * n), defa{_defa}, merge{_merge} {}
		void modify(int p, const value_t& x) {
			for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
		}
		value_t query(int l, int r) { return query(l, r, defa); }
		value_t query(int l, int r, value_t init) { // [l:r)
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if (l & 1) init = merge(init, t[l++]);
				if (r & 1) init = merge(init, t[--r]);
			}
			return init;
		}
	};

	bool solve() {
		int n, k;
		if (!(cin >> n >> k)) return false;

		vector<vector<ll>> dp(k, vector<ll>(n));
		for (int i{0}; i < n; ++i) dp[1][i] = 1; // 1.., 21.., 321.., ...
		for (int j{2}; j < k; ++j) {
			auto& ps{dp[j - 1]};
			for (int i{1}; i < n; ++i) ps[i] = MA(ps[i], ps[i - 1]);
			auto sum{[&ps](int l, int r) {
				return MS(ps[r - 1], (l ? ps[l - 1] : 0));
			}};
			for (int i{0}; i < n; ++i) {
				if (i - 1 >= 0) dp[j][i] = MA(dp[j][i], sum(i - 1, i)); // ..1
				if (i - 3 >= 0) dp[j][i] = MA(dp[j][i], sum(0, i - 3 + 1)); // ..121, ..1221, ..12321, ...
			}
		}
		struct M { ll operator()(ll a, ll b) { return MA(a, b); } };
		SGT<ll, M> sgt(n, 0);
		for (int i{0}; i < n; ++i) sgt.modify(i, dp[k - 1][i]);
		for (int i{0}; i < n; ++i) {
			ll x{sgt.query(i, i + 1)};
			if (i - 1 >= 0) x = MA(x, sgt.query(i - 1, i));
			if (i - 3 >= 0) x = MA(x, sgt.query(0, i - 3 + 1));
			sgt.modify(i, x);
		}

		ll ans{sgt.query(0, n - 1)}; // ..1, ..12, ..123, ...

		cout << ans << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
