//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <optional>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll PM{1000000007};
	ll MA(ll a, ll b) { return (a + b) % PM; }
	ll IMP{numeric_limits<ll>::max()};

	using dll = array<ll, 2>;
	dll dmin(dll a, dll b) {
		if (a[0] > b[0]) swap(a, b);
		if (a[0] == b[0]) return {a[0], MA(a[1], b[1])};
		return a;
	}
	// segment tree
	// range query & range modify
	class SGT {
		using value_t = dll;

		int n;
		vector<value_t> t;
		vector<optional<value_t>> lz;
		// [ tv+1 : tv+2*(tm-tl) ) -> left subtree
		int left(int tv) { return tv + 1; }
		int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
		/** differ from case to case **/
		// query is "max" and modify is "add" here
		value_t merge(const value_t& x, const value_t& y) { // associative function
			return dmin(x, y);
		}
		void update(int tv, int len, const value_t& x) {
			if (!lz[tv]) lz[tv] = x;
			else lz[tv] = dmin(lz[tv].value(), x);
			t[tv] = dmin(t[tv], x);
		}
		/******************************/
		void build(const vector<value_t>& v, int tv, int tl, int tr) {
			if (tr - tl > 1) {
				int tm{(tl + tr) / 2};
				build(v, left(tv), tl, tm);
				build(v, right(tv, tl, tm), tm, tr);
				t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
			} else t[tv] = v[tl];
		}
		void push(int tv, int tl, int tr) { // lazy propagation
			if (!lz[tv]) return ;
			int tm{(tl + tr) / 2};
			update(left(tv), tm - tl, lz[tv].value());
			update(right(tv, tl, tm), tr - tm, lz[tv].value());
			lz[tv].reset();
		}
		void set(int p, const value_t& x, int tv, int tl, int tr) {
			if (tr - tl > 1) {
				push(tv, tl, tr);
				int tm{(tl + tr) / 2};
				if (p < tm) set(p, x, left(tv), tl, tm);
				else set(p, x, right(tv, tl, tm), tm, tr);
				t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
			} else t[tv] = x;
		}
		void rmodify(int l, int r, const value_t& x, int tv, int tl, int tr) {
			if (!(l == tl && r == tr)) {
				push(tv, tl, tr);
				int tm{(tl + tr) / 2};
				if (r <= tm) rmodify(l, r, x, left(tv), tl, tm);
				else if (l >= tm) rmodify(l, r, x, right(tv, tl, tm), tm, tr);
				else rmodify(l, tm, x, left(tv), tl, tm),
					rmodify(tm, r, x, right(tv, tl, tm), tm, tr);
				t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
			} else update(tv, tr - tl, x);
		}
		value_t rquery(int l, int r, int tv, int tl, int tr) {
			if (l == tl && r == tr) return t[tv];
			push(tv, tl, tr);
			int tm{(tl + tr) / 2};
			if (r <= tm) return rquery(l, r, left(tv), tl, tm);
			else if (l >= tm) return rquery(l, r, right(tv, tl, tm), tm, tr);
			else return merge(rquery(l, tm, left(tv), tl, tm),
				rquery(tm, r, right(tv, tl, tm), tm, tr));
		}
	public:
		explicit SGT(const vector<value_t>& v) : n{v.size()}, t(2 * n - 1), lz(2 * n - 1) { build(v, 0, 0, n); }
		void set(int p, const value_t& x) { set(p, x, 0, 0, n); }
		void rmodify(int l, int r, const value_t& x) { rmodify(l, r, x, 0, 0, n); } // [l:r)
		value_t query(int p) { return rquery(p, p + 1, 0, 0, n); }
		value_t rquery(int l, int r) { return rquery(l, r, 0, 0, n); } // [l:r)
	};
	void solve() {
		int n1, n2;
		cin >> n1 >> n2;
		vector<ll> a(n1), b(n2);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		vector<ll> pa(n1 + 1);
		for (int i{0}; i < n1; ++i) pa[i + 1] = pa[i] + a[i];

		vector<SGT> dp(n2, SGT{vector<dll>(n1 + 1, {IMP, 0})});
		dp[0].set(0, {0, 1});
		for (int i{0}; i < n1; ++i) {
			dll t{IMP, 0};
			for (int j{0}; j < n2; ++j) {
				t = dmin(t, dp[j].query(i));
				if (t[0] == IMP) continue;

				int l{i - 1}, r{n1};
				while (r - l > 1) {
					int m{(l + r) / 2};
					if (pa[m + 1] - pa[i] <= b[j]) l = m;
					else r = m;
				}
				if (l == i - 1) continue;

				dp[j].rmodify(i + 1, l + 1 + 1, {t[0] + n2 - (j + 1), t[1]});
			}
		}

		dll ans{IMP, 0};
		for (int j{0}; j < n2; ++j) ans = dmin(ans, dp[j].query(n1));

		if (ans[0] == IMP) cout << "-1\n";
		else cout << ans[0] << ' ' << ans[1] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
