//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
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
	int n; cin >> n;
	vector<int> v(n);
	for (auto& e : v) cin >> e;
	int x; cin >> x;

	vector<int> r(n);
	for (int i{0}, j{1}; j <= n; ) {
		while (j < n && v[j] + v[j - 1] >= 2 * x && (j == i + 1 || v[j] + v[j - 1] + v[j - 2] >= 3 * x)) ++j;
		for (int k{i}; k < j; ++k) r[k] = j - 1;
		if (i < j - 1) i = j - 1;
		else i = j, j = j + 1;
	}

	struct M {
		int operator()(int x, int y) { return min(x, y); }
	};
	SGT<int, M> dp{n + 1};
	for (int i{0}; i < n; ++i) dp.modify(i, n);
	dp.modify(n, 0);
	for (int i{n - 1}; i >= 0; --i) {
		if (r[i] == n - 1) dp.modify(i, 0);
		else dp.modify(i, dp.query(i + 1, r[i] + 3, n) + 1);
	}

	cout << n - dp.query(0, 1, n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
