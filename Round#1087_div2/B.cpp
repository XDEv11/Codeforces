//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

// segment tree
template<typename value_t, class merge_t>
class SGT {
    int n;
    vector<value_t> t; // root starts at 1
    value_t defa;
    merge_t merge; // associative function for SGT
public:
    explicit SGT(int _n, value_t _defa, const merge_t& _merge = merge_t{})
        : n{_n}, t(2 * n), defa{_defa}, merge{_merge} {}
    void modify(int p, const value_t& x) {
        for (t[p += n] = x; p > 1; p >>= 1) t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    value_t query(int l, int r) { return query(l, r, defa); }
    value_t query(int l, int r, value_t init) { // [l:r)
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) init = merge(init, t[l++]);
            if (r & 1) init = merge(init, t[--r]);
        }
        return init;
    }
};

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		map<int, int> mp{};
		for (int i{0}; i < n; ++i) mp[v[i]];
		int m{};
		for (auto& [x, k] : mp) k = m++;

		vector<int> ans(n);
		SGT<int, plus<int>> sgt{m, 0};
		for (int i{n - 1}; i >= 0; --i) {
			int k{mp[v[i]]};
			ans[i] = max(sgt.query(0, k), sgt.query(k + 1, m));
			sgt.modify(k, sgt.query(k, k + 1) + 1);
		}

		for (auto& x : ans) cout << x << ' ';
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
