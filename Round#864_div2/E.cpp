//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#define fi first
#define se second

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> pa, sz, la;
	int find(int x) { // collapsing find
		return pa[x] == -1 ? x : pa[x] = find(pa[x]);
	}
	void unionn(int x, int y) { // weighted union
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		pa[ry] = rx, sz[rx] += sz[ry], la[rx] = max(la[rx], la[ry]);
	}
public:
	explicit DSU(int n) : pa(n + 1, -1), sz(n + 1, 1), la(n + 1) { iota(la.begin(), la.end(), 0); }
	int next(int x) {
		return la[find(x + 1)] + 1 - 1;
	}
	void remove(int x) {
		unionn(x - 1 + 1, x + 1);
	}
};

// sparse table
template<typename value_t, class merge_t>
class ST {
    int n;
    vector<int> log2;
    vector<vector<value_t>> t;
    merge_t merge; // associative & idempotent function for ST
public:
    explicit ST(const vector<value_t>& v, const merge_t& _merge = merge_t{})
        : n{v.size()}, log2(n + 1), merge{_merge} {
        log2[1] = 0;
        for (int i{2}; i <= n; ++i) log2[i] = log2[i / 2] + 1;

        t.assign(n, vector<value_t>(log2[n] + 1));
        for (int i{n - 1}; i >= 0; --i) {
            t[i][0] = v[i];
            for (int j{1}; i + (1 << j) <= n; ++j)
                t[i][j] = merge(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
    value_t query(int l, int r) { // [l:r)
        int j{log2[r - l]};
        return merge(t[l][j], t[r - (1 << j)][j]);
    }
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

static constexpr int mxv{5000000};
static const vector<int> phi_val{[] {
	vector<int> v(mxv + 1); v[1] = 1;
	for (int i{2}; i <= mxv; ++i) {
		if (v[i]) continue;
		v[i] = i;
		for (int j{i}; j <= mxv; j += i) {
			if (!v[j]) v[j] = j;
			v[j] = v[j] / i * (i - 1);
		}
	}
	return v;
}()};
static const vector<int> phi_dep{[] {
	vector<int> v(mxv + 1); v[1] = 1;
	for (int i{2}; i <= mxv; ++i) v[i] = v[phi_val[i]] + 1;
	return v;
}()};
class PHI_LCA {
	mutable vector<bool> ck;
public:
	PHI_LCA() : ck(mxv + 1) { ck[1] = true; }
	int operator()(int u, int v) const {
		for (int x{u}; x != 1; x = phi_val[x]) ck[x] = true;
		while (!ck[v]) v = phi_val[v];
		for (int x{u}; x != 1; x = phi_val[x]) ck[x] = false;
		return v;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	ST<int, PHI_LCA> st{v};

	vector<int> d(n);
	for (int i{0}; i < n; ++i) d[i] = phi_dep[v[i]];

	DSU dsu{n};
	for (int i{0}; i < n; ++i) {
		if (d[i] == 1) dsu.remove(i);
	}

	using sgt_value_t = pair<int, int>;
	struct sgt_merge_t {
		sgt_value_t operator()(sgt_value_t a, sgt_value_t b) { return {a.fi + b.fi, min(a.se, b.se)}; }
	};
	SGT<sgt_value_t, sgt_merge_t> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, {d[i], d[i]});

	while (m--) {
		int op, l, r;
		cin >> op >> l >> r, --l;

		if (op == 1) {
			int x{dsu.next(l - 1)};
			while (x < r) {
				--d[x], sgt.modify(x, {d[x], d[x]});
				if (d[x] == 1) dsu.remove(x);
				x = dsu.next(x);
			}
		} else if (op == 2) {
			auto [ans1, ans2]{sgt.query(l, r, {0, mxv})};
			ans2 = min(ans2, phi_dep[st.query(l, r)]);
			ans2 *= (r - l);
			cout << ans1 - ans2 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
