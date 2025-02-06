//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

// fast disjoint set union
class DSU {
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
    explicit DSU(int n) : pa(n, -1), sz(n, 1), mn(n) { iota(mn.begin(), mn.end(), 0), mx = mn; }
	void remove(int i) { if (i + 1 < pa.size()) unionn(i, i + 1); }
	int left(int i) { return mn[find(i)] - 1; }
	int right(int i) { return mx[find(i)]; }
};

// segment tree
template<typename value_t, class merge_t>
class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    merge_t merge; // associative function for SGT
public:
    explicit SGT(int _n, const merge_t& _merge = merge_t{})
        : n{_n}, t(2 * n), merge{_merge} {}
    void modify(int p, const value_t& x) {
        for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    value_t query(int l, int r, value_t init) { // [l:r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) init = merge(init, t[l++]);
            if (r & 1) init = merge(init, t[--r]);
        }
        return init;
    }
};

bool solve() {
	int n, m, q;
	if (!(cin >> n >> m >> q)) return false;
	vector<int> v(n, -1);
	{
		vector<int> v1(m), v2(m);
		for (auto& x : v1) cin >> x, --x;
		for (auto& x : v2) cin >> x;
		for (int i{0}; i < m; ++i) v[v1[i]] = v2[i];
	}

	vector<array<int, 3>> a(q);
	for (auto& [t, x, y] : a) {
		cin >> t >> x >> y, --x;
		if (t == 2) --y;
	}

	for (auto& [t, x, y] : a) {
		if (t == 1) v[x] = y;
	}

	DSU dsu{n};
	for (int i{0}; i < n; ++i) {
		if (v[i] == -1) dsu.remove(i);
	}

	SGT<ll, plus<ll>> sgt{n};
	for (int i{1}; i < n; ++i) {
		if (v[i] != -1) {
			int j{dsu.left(i)}, l{i - (j + 1)};
			sgt.modify(i, ll(l) * (l + 1) / 2 * v[j]);
		}
	}

	vector<ll> ans{};
	reverse(a.begin(), a.end());
	for (auto& [t, x, y] : a) {
		if (t == 1) {
			v[x] = -1, dsu.remove(x);
			sgt.modify(x, 0);
			int i{dsu.right(x)}, j{dsu.left(x)}, l{i - (j + 1)};
			sgt.modify(i, ll(l) * (l + 1) / 2 * v[j]);
		} else if (t == 2) {
			ll c{};
			int i, j;
			if (v[x] == -1) {
				i = dsu.right(x);
				int l{i - x};
				c += ll(l) * (l + 1) / 2 * v[dsu.left(x)];
			} else i = x;
			if (v[y] == -1) {
				j = dsu.right(y);
				int l{j - (y + 1)};
				c -= ll(l) * (l + 1) / 2 * v[dsu.left(y)];
			} else j = y;
			ans.push_back(c += sgt.query(i + 1, j + 1, 0));
		}
	}
	reverse(ans.begin(), ans.end());

	for (auto& x : ans) cout << x << ' ';
	return cout << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
