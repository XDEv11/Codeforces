//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include <limits>

using namespace std;

// segment tree
// range query & range modify
template <typename value_t>
class SGT {
    using node_t = value_t;

    int n;
    vector<node_t> t;
    vector<optional<value_t>> lz;
    // [ tv+1 : tv+2*(tm-tl) ) -> left subtree
    int left(int tv) { return tv + 1; }
    int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    /** differ from case to case **/
    // query is "sum, max" and modify is "set" here
    node_t merge(const node_t& x, const node_t& y) { // associative function
        return x + y;
    }
    void update(int tv, int len, const value_t& x) {
        lz[tv] = x;
        t[tv] = len * x;
    }
    /******************************/
    void push(int tv, int tl, int tr) { // lazy propagation
        if (!lz[tv]) return ;

        int tm{(tl + tr) / 2};
        update(left(tv), tm - tl, lz[tv].value());
        update(right(tv, tl, tm), tr - tm, lz[tv].value());
        lz[tv].reset();
    }
    void modify(int l, int r, const value_t& x, int tv, int tl, int tr) {
        if (l == tl && r == tr) update(tv, tr - tl, x);
        else {
            push(tv, tl, tr);
            int tm{(tl + tr) / 2};
            if (r <= tm) modify(l, r, x, left(tv), tl, tm);
            else if (l >= tm) modify(l, r, x, right(tv, tl, tm), tm, tr);
            else modify(l, tm, x, left(tv), tl, tm),
                modify(tm, r, x, right(tv, tl, tm), tm, tr);
            t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
        }
    }
    node_t query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        push(tv, tl, tr);
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return merge(query(l, tm, left(tv), tl, tm),
                query(tm, r, right(tv, tl, tm), tm, tr));
    }
public:
    explicit SGT(int _n) : n{_n}, t(2 * n - 1), lz(2 * n - 1) {}
    void modify(int l, int r, const value_t& x) { modify(l, r, x, 0, 0, n); } // [l:r)
    node_t query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll c{0}, d{0};
	vector<ll> c1(n), d1(n);
	SGT<ll> sgt{n};
	for (int i{0}; i < n; ++i) {
		ll x{v[i] - i}; 

		int l{-1}, r{i};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (sgt.query(m, m + 1) <= x) l = m;
			else r = m;
		}
		if (r < i) c += sgt.query(r, i) - x * (i - r);
		d = max(d, -x);
		sgt.modify(r, i + 1, x);

		c1[i] = c, d1[i] = d;
	}

	c = 0, d = 0;
	vector<ll> c2(n), d2(n);
	for (int i{n - 1}; i >= 0; --i) {
		ll x{v[i] - (n - 1 - i)}; 

		int l{i}, r{n};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (sgt.query(m, m + 1) <= x) r = m;
			else l = m;
		}
		if (i < l) c += sgt.query(i + 1, l + 1) - x * ((l + 1) - (i + 1));
		d = max(d, -x);
		sgt.modify(i, l + 1, x);

		c2[i] = c, d2[i] = d;
	}

	ll ans{numeric_limits<ll>::max()};
	for (int i{0}; i < n; ++i) ans = min(ans,
			v[i] + (c2[i] - d2[i] * (d2[i] + 1) / 2) + (c1[i] - d1[i] * (d1[i] + 1) / 2));

	cout << ans << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
