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
	using pii = pair<int, int>;

	int n;
	cin >> n;
	vector<pii> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	for (auto& [x, y] : v) {
		int k{29};
		while (k >= 1 && (y >> k) == (x >> k)) --k;
		int m{(1 << (k + 1)) - 1};
		x = y, y = k ? (x & m) : 0;
	}

	struct M {
		pii operator()(pii a, pii b) {
			auto& [av, at]{a};
			auto& [bv, bt]{b};
			for (int k{29}; k >= 1; --k) {
				if ((av & (1 << k)) && (bv & (1 << k)) && ((at | bt) & (1 << k))) {
					int m{(1 << k) - 1};
					return {av | bv | m, at | bt | m};
				}
			}
			return {av | bv, at | bt};
		}
	};
	SGT<pii, M> sgt{n};
	for (int i{0}; i < n; ++i) sgt.modify(i, v[i]);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

		cout << sgt.query(l, r + 1, {0, 0}).fi << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
