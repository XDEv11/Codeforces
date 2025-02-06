//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <optional>
#include <numeric>
#include <algorithm>

using namespace std;

// segment tree
// range query & range modify
template<typename value_t>
class SGT {
	using node_t = pair<value_t, int>;

	int n;
	vector<node_t> t;
	vector<optional<value_t>> lz;
	// [ tv+1 : tv+2*(tm-tl) ) -> left subtree
	int left(int tv) { return tv + 1; }
	int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	/** differ from case to case **/
	// query is "min" and modify is "set" here
	node_t merge(const node_t& x, const node_t& y) { // associative function
		return min(x, y);
	}
	void update(int tv, int len, const value_t& x) {
		if (!lz[tv]) lz[tv] = x;
		else lz[tv] = min(lz[tv].value(), x);
		t[tv].fi = min(t[tv].fi, x);
	}
	/******************************/
	void build(const vector<value_t>& v, int tv, int tl, int tr) {
		if (tr - tl > 1) {
			int tm{(tl + tr) / 2};
			build(v, left(tv), tl, tm);
			build(v, right(tv, tl, tm), tm, tr);
			t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
		} else t[tv] = {v[tl], tl};
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
		} else t[tv].fi = x;
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
	node_t rquery(int l, int r, int tv, int tl, int tr) {
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
	node_t rquery(int l, int r) { return rquery(l, r, 0, 0, n); } // [l:r)
};

namespace {
	void solve() {
		using ll = long long;

		int n;
		cin >> n;
		vector<ll> a(n);
		vector<int> b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x, --x;

		SGT<ll> dp{vector<ll>(n, accumulate(a.begin(), a.end(), 0ll))};
		dp.set(0, 0);
		for (int i{0}; i < n; ++i) {
			if (b[i] > i) dp.rmodify(i + 1, b[i] + 1, dp.rquery(i, i + 1).fi + a[i]);
		}

		ll ans{}, s{};
		for (int i{0}; i < n; ++i) {
			s += a[i];
			ans = max(ans, s - dp.rquery(i, i + 1).fi);
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
