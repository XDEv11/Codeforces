//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <optional>
#include <utility>
#define fi first
#define se second
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
	// query is "min" and modify is "add" here
	node_t merge(const node_t& x, const node_t& y) { // associative function
		return min(x, y);
	}
	void update(int tv, int len, const value_t& x) {
		if (!lz[tv]) lz[tv] = x;
		else lz[tv] = lz[tv].value() + x;
		t[tv].fi = t[tv].fi + x;
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
	void rmodify(int l, int r, const value_t& x) { rmodify(l, r, x, 0, 0, n); } // [l:r)
	node_t rquery(int l, int r) { return rquery(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	using ll = long long;

	int n, k, a;
	cin >> n >> k >> a;
	vector<vector<pair<int, int>>> p(k + 1);
	for (int i{0}; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		p[y].emplace_back(x, c);
	}

	vector<ll> dp(k + 1);
	SGT<ll> sgt{vector<ll>(k + 1)};
	ll all{};
	for (int i{1}; i <= k; ++i) {
		sgt.rmodify(0, i, a);
		ll cnt{};
		for (auto& [x, c] : p[k - i]) {
			cnt += c;
			if (x + 1 < i) sgt.rmodify(x + 1, i, c);
		}
		dp[i] = min(dp[i - 1] + cnt, sgt.rquery(0, i).fi);
		sgt.rmodify(i, i + 1, dp[i]);
	}

	cout << dp[k] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
