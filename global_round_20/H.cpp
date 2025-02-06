//#pragma GCC optimize ("O3")

#include <ios>
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
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	SGT<int, plus<int>> sgt{n - 1};
	for (int i{0}; i < n - 1; ++i) sgt.modify(i, v[i] == v[i + 1]);

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		int c{sgt.query(l, r, 0)}; 
		if (c == r - l) cout << c + 1 << '\n';
		cout << 1 + << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
