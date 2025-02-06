//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
		for (auto& x : v) cin >> x, --x;

		vector<int> a(n);
		SGT<int, plus<int>> sgt1{n, 0};
		for (int i{0}; i < n; ++i) sgt1.modify(v[i], 1);

		struct MIN { int operator()(int a, int b) { return min(a, b); } };
		SGT<int, MIN> sgt2{n, n};
		for (int i{0}; i < n; ++i) sgt2.modify(v[i], i);

		for (int k{0}, i{0}; k < n; ++k) {
			while (!sgt1.query(v[i], v[i] + 1)) ++i;
			int j{i};
			while (sgt1.query(0, v[j] + 1) % 2 == 0) j = sgt2.query(0, v[j]);

			a[j] = k;
			sgt1.modify(v[j], 0), sgt2.modify(v[j], n);
		}

		for (auto& x : a) cout << (x + 1) << ' ';
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
