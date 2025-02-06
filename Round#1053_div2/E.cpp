//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
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
    value_t query(int p) { return query(p, p + 1, defa); }
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
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		vector<int> a(n), b(n);
		for (auto& x : v) cin >> x;
		for (auto& x : b) cin >> x, --x;
		for (auto& x : a) cin >> x, --x;

		vector<int> ia(n);
		for (int i{0}; i < n; ++i) ia[a[i]] = i;

		SGT<ll, plus<ll>> sgt{n, 0};
		for (int i{0}; i < n; ++i) sgt.modify(ia[i], v[i]);

		ll ans{};
		for (int j{0}, k{0}; j < n; ++j) {
			ll x{sgt.query(ia[b[j]])};
			if (x >= 0) ans += x;
			else {
				if (sgt.query(0, ia[b[j]] + 1) < 0) {
					while (k < ia[b[j]]) sgt.modify(k++, 0);
					++k;
				} else ans += x;
			}
			sgt.modify(ia[b[j]], 0);
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
