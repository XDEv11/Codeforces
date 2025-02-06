//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second
#include <numeric>
#include <functional>

using namespace std;

// fast disjoint set union
class DSU {
    vector<int> pa, sz, mx;
    int find(int x) { // collapsing find
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unionn(int x, int y) { // weighted union
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        pa[ry] = rx, sz[rx] += sz[ry], mx[rx] = max(mx[rx], mx[ry]);
    }
public:
    explicit DSU(int n) : pa(n, -1), sz(n, 1), mx(n) { iota(mx.begin(), mx.end(), 0); }
	void remove(int i) { unionn(i, i + 1); };
	int next(int i) { return mx[find(i)]; }
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

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<char> v(n);
	vector<pair<int, int>> t(m);
	vector<int> u(q);
	for (auto& x : v) cin >> x;
	for (auto& [l, r] : t) cin >> l >> r, --l, --r;
	for (auto& p : u) cin >> p, --p;

	DSU dsu{n + 1};

	vector<int> od{};
	for (auto& [l, r] : t) {
		for (int i{dsu.next(l)}; i <= r; i = dsu.next(i + 1)) od.push_back(i), dsu.remove(i);
	}
	m = od.size();

	vector<int> idx(n, -1);
	for (int i{0}; i < m; ++i) idx[od[i]] = i;

	int c{};
	for (int i{0}; i < n; ++i) c += (v[i] == '1');
	SGT<int, plus<int>> sgt{m};
	for (int i{0}; i < m; ++i) sgt.modify(i, v[od[i]] == '1');

	for (auto& p : u) {
		if (v[p] == '1') v[p] = '0', --c;
		else v[p] = '1', ++c;
		int i{idx[p]};
		if (i != -1) sgt.modify(i, !sgt.query(i, i + 1, 0));

		if (!c) cout << 0 << '\n';
		else cout << min(m, c) - sgt.query(0, min(m, c), 0) << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
