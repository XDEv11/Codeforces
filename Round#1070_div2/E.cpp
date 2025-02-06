//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <optional>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

// previous/next one
class PvNx {
    vector<int> pa, sz, mn, mx;
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry], mn[rx] = min(mn[rx], mn[ry]), mx[rx] = max(mx[rx], mx[ry]);
    }
public:
    explicit PvNx(int n) : pa(n + 1, -1), sz(n + 1, 1), mn(n + 1) { iota(mn.begin(), mn.end(), 0), mx = mn; }
    void remove(int i) { unionn(i, i + 1); }
    int prev(int i) { return mn[find(i)] - 1; }
    int next(int i) {
        int j{mx[find(i)]};
        if (i == j) j = mx[find(j + 1)];
        return j;
    }
    bool exist(int i) { return i == mx[find(i)]; }
};

// segment tree
class SGT {
    using value_t = ll;
	using node_t = pair<value_t, value_t>;

    int n;
    vector<node_t> t;
    // [ tv+1 : tv+2*(tm-tl) ) -> left subtree
    int left(int tv) { return tv + 1; }
    int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    node_t merge(const node_t& x, const node_t& y) { // associative function
		return {x.fi + y.fi, max(x.se, y.se)};
    }
    /******************************/
    void set(int p, const value_t& x, int tv, int tl, int tr) {
        if (tr - tl > 1) {
            int tm{(tl + tr) / 2};
            if (p < tm) set(p, x, left(tv), tl, tm);
            else set(p, x, right(tv, tl, tm), tm, tr);
            t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
        } else t[tv] = {x, x};
    }
    node_t query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return merge(query(l, tm, left(tv), tl, tm),
            query(tm, r, right(tv, tl, tm), tm, tr));
    }
public:
    explicit SGT(int _n) : n{_n}, t(2 * n - 1) {}
    void set(int p, const value_t& x) { set(p, x, 0, 0, n); }
    node_t query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<ll> a(n), c(n), p(n);
		for (auto& x : a) cin >> x;
		for (auto& x : c) cin >> x;
		for (auto& x : p) cin >> x, --x;

		vector<pair<ll, int>> t(n);
		for (int i{0}; i < n; ++i) t[i] = {c[i], i};
		sort(t.begin(), t.end());

		SGT sgt{n};
		PvNx pn{n};
		for (auto& [x, i] : t) {
			if (!pn.exist(i)) continue;
			sgt.set(i, x), pn.remove(i);
			for (int j{pn.next(i)}; j < n; j = pn.next(j)) {
				if (a[j] > a[i]) break;
				sgt.set(j, x), pn.remove(j);
			}
			for (int j{pn.prev(i)}; j >= 0; j = pn.prev(j)) {
				if (a[j] > a[i]) break;
				sgt.set(j, x), pn.remove(j);
			}
		}

		pn = PvNx{n};
		for (int k{0}; k <= n; ++k) {
			auto [s, mx]{sgt.query(0, n)};
			cout << s - mx << ' ';
			if (k == n) continue;

			auto i{p[k]};
			if (!pn.exist(i)) continue;
			sgt.set(i, 0), pn.remove(i);
			for (int j{pn.next(i)}; j < n; j = pn.next(j)) {
				if (a[j] > a[i]) break;
				sgt.set(j, 0), pn.remove(j);
			}
			for (int j{pn.prev(i)}; j >= 0; j = pn.prev(j)) {
				if (a[j] > a[i]) break;
				sgt.set(j, 0), pn.remove(j);
			}
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
