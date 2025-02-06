//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

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
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;
	vector<vector<pair<int, int>>> qry(n);
	for (int i{0}; i < q; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		qry[r].emplace_back(l, i);
	}

	vector<int> rst(q);
	struct idx_merge_t { int operator()(int a, int b) const { return max(a, b); } };
	SGT<int, idx_merge_t> idx{n};
	for (int i{0}; i < n; ++i) idx.modify(i, -1);
	struct ans_merge_t { int operator()(int a, int b) const { return min(a, b); } };
	SGT<int, ans_merge_t> ans{n};
	for (int i{0}; i < n; ++i) ans.modify(i, n);
	for (int i{0}; i < n; ++i) {
		int b{n - 1};
		while (true) {
			int j{idx.query(v[i], b + 1, -1)};
			if (j == -1) break;
			ans.modify(j, min(ans.query(j, j + 1, n), v[j] - v[i]));
			b = v[i] + (v[j] - v[i] - 1) / 2;
		}
		b = 0;
		while (true) {
			int j{idx.query(b, v[i] + 1, -1)};
			if (j == -1) break;
			ans.modify(j, min(ans.query(j, j + 1, n), v[i] - v[j]));
			b = v[i] - (v[i] - v[j] - 1) / 2;
		}
		idx.modify(v[i], i);
		for (auto& [l, k] : qry[i]) rst[k] = ans.query(l, i, n);
	}

	for (auto& x : rst) cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
