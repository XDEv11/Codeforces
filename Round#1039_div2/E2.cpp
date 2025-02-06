//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

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

class SGT {
    int n;
    vector<long long> t;
    int left(int tv) { return tv + 1; }
    int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
    void modify(int p, long long x, int tv, int tl, int tr) {
        if (tr - tl > 1) {
            int tm{(tl + tr) / 2};
            if (p < tm) modify(p, x, left(tv), tl, tm);
            else modify(p, x, right(tv, tl, tm), tm, tr);
            t[tv] = t[left(tv)] + t[right(tv, tl, tm)];
        } else t[tv] += x;
    }
    long long query(int l, int r, int tv, int tl, int tr) {
        if (l == tl && r == tr) return t[tv];
        int tm{(tl + tr) / 2};
        if (r <= tm) return query(l, r, left(tv), tl, tm);
        else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
        else return query(l, tm, left(tv), tl, tm) +
            query(tm, r, right(tv, tl, tm), tm, tr);
    }
public:
    explicit SGT(int _n) : n{_n}, t(2 * n - 1) {}
    void modify(int p, long long x) { modify(p, x, 0, 0, n); };
    long long query(int l, int r) { return query(l, r, 0, 0, n); }
    int pb(long long ps) { // prefix sum lower bound
        if (ps > t[0]) return n;
        int tv{0}, tl{0}, tr{n};
        while (tr - tl > 1) {
            int tm{(tl + tr) / 2};
            if (t[left(tv)] >= ps) tv = left(tv), tr = tm;
            else ps -= t[left(tv)], tv = right(tv, tl, tm), tl = tm;
        }
        return tl;
    }
};

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		auto check{[&](int m, const auto& c) -> array<int, 2> {
			vector<int> t(n + 1);
			for (int i{0}; i < n; ++i) t[i + 1] = t[i] + (c(v[i], m) ? -1 : 1);
			for (int i{k - 1}, j{-1}; i < n; ++i) {
				if (t[i - k + 1] < t[j + 1]) j = i - k;
				if (t[i + 1] - t[j + 1] >= 0) return {j + 1, i};
			}
			return {-1, -1};
		}};
		// find the extremal x such that there exists a subarray in which !c(v[i], x) holds for a majority
		auto bsearch{[&](const auto& c) -> array<int, 3> {
			int l{0}, r{n + 1};
			bool f{c(l, r)}; // whether check(l) is true
			array<int, 2> s;
			while (r - l > 1) {
				int m{(l + r) / 2};
				s = check(m, c);
				((s[0] == -1) == f ? r : l) = m;
			}
			s = check(f ? l : r, c);
			return {f ? l : r, s[0], s[1]};
		}};
		auto mx{bsearch(less<int>{})}, mn{bsearch(greater<int>{})};

		vector<array<int, 2>> ans(n + 1);
		PvNx pn{n + 1};
		int l, r;
		SGT sgt{n + 1};
		auto addans{[&] {
			for (int i{pn.next(sgt.pb((r - l - 1) / 2 + 1) - 1)}; i <= sgt.pb((r - l) / 2 + 1); i = pn.next(i)) {
				ans[i] = {l, r}, pn.remove(i);
			}
		}};
		if (mx[2] > mn[2]) swap(mx, mn);
		l = mx[1], r = l;
		while (r <= mx[2]) sgt.modify(v[r++], 1);
		addans();
		while (r <= mn[2]) sgt.modify(v[r++], 1), addans();
		while (l > mn[1]) sgt.modify(v[--l], 1), addans();
		while (l < mn[1]) sgt.modify(v[l++], -1), addans();
		if (mx[0] < mn[0]) swap(mx, mn);

		cout << mx[0] - mn[0] + 1 << '\n';
		for (int i{mn[0]}; i <= mx[0]; ++i) cout << i << ' ' << ans[i][0] + 1 << ' ' << ans[i][1] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
