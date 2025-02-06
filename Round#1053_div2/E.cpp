//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <optional>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

// segment tree
// range query & range modify
class SGT {
    using value_t = ll;
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
		int n;
		cin >> n;
		vector<ll> _v(n), v(n);
		vector<int> a(n), _b(n), b(n);
		for (auto& x : _v) cin >> x;
		for (auto& x : a) cin >> x, --x;
		for (auto& x : _b) cin >> x, --x;
		vector<int> ia(n);
		for (int i{0}; i < n; ++i) ia[a[i]] = i;
		for (int i{0}; i < n; ++i) v[i] = _v[a[i]];
		for (int i{0}; i < n; ++i) b[ia[_b[i]]] = i;

		SGT dp{vector<ll>(n + 1)};
		for (auto& x : b) ++x;
		for (int i{0}; i < n; ++i) {
			if (b[i] < n) dp.rmodify(b[i] + 1, n + 1, v[i]);
			dp.set(b[i], dp.rquery(0, b[i]).fi + v[i]);
		}
		ll ans{accumulate(v.begin(), v.end(), 0ll) - dp.rquery(0, n + 1).fi};

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
