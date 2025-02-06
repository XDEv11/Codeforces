//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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
	using ll = long long;
	const ll ll_max{numeric_limits<ll>::max()};

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vector<ll> c(k), h(k);
	for (auto& x : v) cin >> x, --x;
	for (auto& x : c) cin >> x;
	for (auto& x : h) cin >> x;

	struct M{ ll operator()(ll x, ll y) { return min(x, y); } };
	SGT<ll, M> sgt{k}; ll aux{c[v[0]]};
	for (int i{0}; i < k; ++i) sgt.modify(i, ll_max);
	sgt.modify(v[0], 0);
	for (int i{1}; i < n; ++i) {
		if (v[i] != v[i - 1]) {
			// replace v[i - 1]
			aux += c[v[i]];
			// replace j
			ll dp_v_is1{sgt.query(v[i - 1], v[i - 1] + 1, ll_max)},
			   dp_v_i{sgt.query(v[i], v[i] + 1, ll_max)},
			   mn{min(dp_v_is1, dp_v_i - c[v[i]] + h[v[i]])};
			sgt.modify(v[i - 1], mn);
			sgt.modify(v[i], mn);
		} else aux += h[v[i]];
	}

	cout << sgt.query(v[n - 1], v[n - 1] + 1, ll_max) + aux << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
