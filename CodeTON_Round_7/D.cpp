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
	for (auto& x : v) cin >> x;

	SGT<int, plus<int>> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);
	while (q--) {
		int op, a, b;
		cin >> op >> a;
		if (op == 1) {
			if (a > sgt.query(0, n, 0)) {
				cout << "NO\n";
				continue;
			}
			int l{0}, r{n + 1};
			while (r - l > 1) {
				int m{(l + r) / 2};
				if (sgt.query(0, m, 0) <= a) l = m;
				else r = m;
			}
			cout << (sgt.query(0, l, 0) == a ||
					sgt.query(l, n, 0) < 2 * (n - l) ||
					sgt.query(0, n - l, 0) < 2 * (n - l) ?
					"YES\n" : "NO\n");
		} else if (op == 2) --a, cin >> b, sgt.modify(a, b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
